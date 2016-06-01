#include <iostream>
#include <stdlib.h>
using namespace std;
long int a[1000000];
int main()
{
	bool flag=false;
	long int n,count=0;
	cin>>n;
	for (long int i = 0; i < n; ++i)
	{
		cin>>a[i];
		if (a[i] == i)
		{
			count++;
		}
	}
	for (long int i = 0; i < n; ++i)
	{
		if(i == a[a[i]] && a[i] != i)
		{
			flag=true;
			break;
		}
	}
	if( !flag && count < n) count++;
	else if (flag && count < n) count+=2;
	else if (!flag && count == n) count-=2;
	cout<<count;
}