#include <iostream>
using namespace std;
struct node
{
	node *left, *right;
	long long int data;
};
class bst
{

	private:
		node *curr,*root;
		
	public:
		bst()
		{
			root=NULL;
			root->data=0;
			curr=root;
			formBST(h,root);
		}
		long long int k=1;
		void formBST(int h,node* root)
		{
			node* newNode= new node();
			newNode->data=k++;
			h--;
			if(h)
			{
				if(k%2==0)
				{
					root->left=newNode;
					formBST(h,root->left);
				}
				else
				{
					root->right=newNode;
					formBST(h,root->right);
				}
			}
			else 
			{
				h++;
				return;
			}
		}
};
int main()
{
	long long int n;
	int h;
	cin>>h>>n;
	bst t=new bst();
	if(n <= (1<<h-1))
		cout<<"less";

}