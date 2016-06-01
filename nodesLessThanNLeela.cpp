#include<iostream>
using namespace std;
struct node
{
    int key;
    struct node *left, *right;
};
node * newNode(int k)
{
    node *temp = new node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}
int inorder(node* root,int n,int count){
    if(root!=NULL){
        count = inorder(root->left,n,count);
        if(root->key<=n)
            count++;
            cout<<count<<" "<<root->key<<" 1e\n";
        count = inorder(root->right,n,count);
    }
    return count;
}
int countNodes(node *root, int n){
    if(root == NULL)
        return 0;
    if(root->key <= n)
        return 1 + countNodes(root->left, n) + countNodes(root->right, n);
    else
        return countNodes(root->left, n) + countNodes(root->right, n);

}
// Driver Program to test above functions
int main()
{
	/* Let us create following BST
			20
		/	 \
	   8	 22
   	  / \   / \
     4 12  21 25 */

    node * root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->right->left = newNode(21);
    root->right->right = newNode(25);
	int n;
	cout<<"enter a number";
	cin>>n;
	int count=0;
	count=countNodes(root,n);
    cout<<count+1<<endl;
	return 0;
}