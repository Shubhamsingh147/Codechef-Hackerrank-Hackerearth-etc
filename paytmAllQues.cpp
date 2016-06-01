#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int key;
    struct Node *left, *right;
};

Node * newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

bool findPath(Node* root, vector<int> &v, int a){

    if(root == NULL)
        return false;
    v.push_back(root->key);
    if(root->key == a)
        return true;
    if (findPath(root->left,v,a) || findPath(root->right,v,a)) return true;
    v.pop_back();
    return false;
}

int findLCA(Node* root,int a, int b){

    if(root == NULL)
        return -1;
    if(a==b)
        return a;
    vector<int> path1, path2;
    if( findPath(root,path1,a) == false || findPath(root,path2,b) == false)
        return -1;
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); ++i)
    {
        if(path1[i] != path2[i])
            break;
    }
    return path2[i-1];
}

void getSumRecur(Node *root, int path[], bool visited[], int pathLen, int k){
    if(root == NULL)
        return;
    path[pathLen] = root->key;
    visited[pathLen] = false;
    pathLen++;
    if(root->left == NULL && root->right == NULL && pathLen-k-1 >= 0 && !visited[pathLen-k-1])
    {
        cout<<path[pathLen-k-1]<<" ";
        visited[pathLen-k-1]=true;
        return;
    }
    getSumRecur(root->left,path,visited,pathLen,k);
    getSumRecur(root->right,path,visited,pathLen,k);
}

int getSumOfNodesAtK(Node* root, int k){

    if(root == NULL)
        return 0;
    bool visited[10000];
    int path[10000];
    getSumRecur(root,path,visited,0,k);    
}

int main()
{
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)<<endl;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)<<endl;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)<<endl;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)<<endl;
    getSumOfNodesAtK(root,2);
    return 0;
}