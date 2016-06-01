#include <bits/stdc++.h>
using namespace std;
int lcp[5000002];
char *s;
int len;
struct node
{
	int data;
	node* next;
};
class ll{

private:
	node *head;
public:
	ll(){
		head = NULL;
	}
	void insert(int x){
		node *newnode = new node();
	    node* nodeptr = new node();  
		newnode->data=x;
		newnode->next=NULL;
		if(head==NULL)
		   head=newnode;
		else
		{  
	        nodeptr=head;
			while(nodeptr->next!=NULL)
				nodeptr=nodeptr->next;
			nodeptr->next=newnode;
		}
	}

	void print(){
		node *temp = new node();
		temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
	void aapHiSambhalo(){
		node *temp = new node();
		node *pre = new node();
		temp = head;
		pre = NULL;
		bool flag = false;
		for (int i = 1; i < len; ++i)
		{
			while(temp!=NULL){
				pre = temp;
				if(s[temp->data] == s[i] && temp->data - i > i)
				{
					lcp[temp->data - i]++;
					if(temp->data + 1 >= len)
						temp->data = temp->data + 1;

				}
				else{
					if(head->next == NULL)
						flag = true;
					if(temp == head){
						head = head->next;
					}
					else
						pre->next = temp->next;
				}
				temp=temp->next;
			}
			if(flag)
				break;
		}

	}
};
int main(){
	s = (char *)malloc(5000002);
	scanf("%s",s);
	ll list;
	char a = s[0];
	len = strlen(s);
	for (int i = 0; i < 5000002; ++i)
	{
		lcp[i] = 0;
	}
	for (int i = 1; i < len; ++i)
	{
		if(s[i] == a){
			list.insert(i+1);
			lcp[i]++;
		}
	}
	list.aapHiSambhalo();
	int q;
	cin>>q;
	int n;
	while(q--){
		scanf("%d", &n);
		printf("%d\n", lcp[n]);
	}
}