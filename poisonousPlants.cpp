#include <iostream>
using namespace std;
struct node{
	long int data;
	node *next;
};
class ll{
private:
	node *head, *curr;
public:
	ll(){
		head = NULL;
		curr = head;
	}
	void insert(long int a){
		
		node *newnode = new node();
		newnode->data = a;
		newnode->next = NULL;
		if(head == NULL)
		{
			head = newnode;
			curr = head;
		}
		else
		{
			curr->next = newnode;
			curr = curr->next;
		}
	}

	void print(){
		node *temp = head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"--";
			temp = temp->next;
		}
		cout<<endl;
	}
	int size(){
		node *temp = head;
		int s = 0;
		while(temp!=NULL){
			s++;
			temp = temp->next;
		}
		return s;
	}
	int find(){
		node *temp;
		int k=-1,len;
		long int val;
		while(1){
			k++;
			temp = head;
			val = temp->data;
			while(temp->next != NULL){
				if(val < temp->next->data){
					val = temp->next->data;
					temp->next = temp->next->next;
				}
				else{
					temp = temp->next;
					val = temp->data;
				}
			}
			if(len == size())
				break;
		}
		return k;
	}
};
int main()
{
	ll psn;
	long int n,a,min;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a;
		psn.insert(a);
	}	
	cout<<psn.find()<<endl;
}