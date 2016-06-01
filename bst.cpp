#include <iostream>
#include <limits.h>
using namespace std;
struct node{
	int key;
	node *left,*right;
}*root;
class BST{
private:
	//node *root;
public:
	void bst(){

	 	root = NULL;
	}
	bool isBST(node *temp = root, int minVal = INT_MIN, int maxVal = INT_MAX){
		if(temp == NULL)
			return true;
		if(temp->key < minVal || temp->key > maxVal)
			return false;
		return isBST(temp->left, minVal, temp->key - 1) && isBST(temp->right, temp->key + 1, maxVal);
	}
	void insert(int n){
		node *newNode = new node;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->key = n;
		if (root == NULL)
			root = newNode;
		else 
		{
			node *curr = root, *parent = root;
			while (curr != NULL)
			{
				parent = curr;
				if (curr->key > n)
					curr = curr->left;
				else
					curr = curr->right;
			}
			if (parent->key > n)
				parent->left = newNode;
			else
				parent->right = newNode;
		}
	}
	void deleteNode(int n = root->key){
		node *temp = root,*parent = root;
		while(temp != NULL)
		{
			parent = temp;
			if (temp->key == n)
				break;
			if (temp->key > n)
				temp = temp->left;
			else
				temp = temp->right;
		}
		if (temp)
		{
			cout<<"Item found! Deleting..."<<endl;
			if (temp->left == NULL && temp->right == NULL){
				cout<<"1"<<endl;
				if (parent->left == temp) 
					parent->left = NULL;
				else
					parent->right = NULL;
				delete temp;
			}
			else if (temp->left == NULL){
				cout<<"2"<<endl;
				parent->right = temp->right;
				parent->left = NULL;
				delete temp;
			}
			else if (temp->right == NULL){
				cout<<"3"<<endl;
				parent->left = temp->left;
				parent->right = NULL;
				delete temp;
			}
			else if (temp->left && temp->right){
				cout<<"4"<<endl;
				node *curr = temp->right, *currParent = temp->right;
				while (curr->left != NULL){
					currParent = curr;
					curr = curr->left;
				}
				temp->key = curr->key;
				currParent->left = NULL;
				delete currParent;
			}
		}
	}
	int max(int a, int b){

		return a>b?a:b;
	}
	int maxLeafToRootSum(int maxSum = 0, node *temp = root){
		if (temp == NULL)
			return 0;
		int val = temp->key + max(maxLeafToRootSum(maxSum, temp->left), maxLeafToRootSum(maxSum, temp->right));
		if (val > maxSum)
			maxSum = val;
		return maxSum;
	}
	int maxLeafToLeafSum(int maxSum = 0, node *temp = root){

		if (temp == NULL)
			return 0;
		int ls = maxLeafToRootSum(0,temp->left);
		int rs = maxLeafToRootSum(0,temp->right);

		int val = ls + temp->key + rs;
		if (val > maxSum)
			maxSum = val;
		return max( maxSum, max(maxLeafToLeafSum(maxSum, temp->left), maxLeafToLeafSum(maxSum, temp->right)));
	}
	int height(node *temp = root){
		if (temp == NULL)
			return 0;
		else
			return 1 + max (height(temp->left), height(temp->right));
	}
	int diameter(node *temp = root){
		if (temp == NULL)
			return 0;
		else
			return height(temp->left)+ 1 + height(temp->right); 
	}
	void inorder(node *temp = root){
		if (temp == NULL)
			return;
		else
		{
			inorder(temp->left);
			cout<<temp->key<<" ";
			inorder(temp->right);
		}
	}
};
int main()
{
	BST bst;
	bst.insert(5);
	bst.insert(2);
	bst.insert(8);
	bst.insert(9);
	bst.insert(1);
	bst.insert(3);
	bst.insert(4);
	bst.inorder();
	cout<<endl;
	cout<<bst.height()<<endl;
	cout<<bst.diameter()<<endl;
	cout<<bst.maxLeafToRootSum()<<endl;
	cout<<bst.maxLeafToLeafSum()<<endl;
	//bst.deleteNode(5);
	//bst.inorder();
	if (bst.isBST())
		cout<<"This is a BST!"<<endl;
	else cout<<"This is'nt a BST"<<endl;
}
/* 
	5
  2   8
 1 3   9
    4 
*/