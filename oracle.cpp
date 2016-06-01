#include <iostream>
#include <stdio.h>
using namespace std;
int i=0,count=1;
int checkForms(int a[], char s[], int l, int r, int n)
{
	int res;
	if(i==r-1)
		return a[r-1];
	i++;
	s[i-1]='+';
	res=a[i-1]+checkForms(a,s,i,r,n);
	cout<<res<<endl;
	return res;
			/*else
			{
				res=a[i-1]-checkForms(a,s,i,r,n);
				s[i-1]='-';
			}
			return res;
			else
			{
				res=a[i-1]*checkForms(a,s,i,r,n);
				s[i-1]='*';
			}
			return res;
			else
			{
				res=a[i-1]/checkForms(a,s,i,r,n);
				s[i-1]='/';
			}
			cout<<res<<endl;
			return res;*/

}
int main()
{
	int n,m;
	cout<<"Enter no.of nos: ";
	cin>>m;
	int a[m];
	char s[m-1];
	for (int i = 0; i < m ; ++i)
	{
		cin>>a[i];
	}
	cin>>n;
	if(checkForms(a,s,0,m,n)==n)
		{
			for(int i=0;i<m;i++)
			{
				if(i!=m-1)
					cout<<a[i]<<s[i];
				else cout<<a[i];
			}
			cout<<endl;
		}
	else
		cout<<"Not possible";
}