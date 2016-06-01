#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

long int maximum(long int a, long int b)
{
	return a>b ? a : b;
}
int main()
{
	int t,m,n;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		int boy[m],girl[n];
		for (int i = 0; i < m; ++i)
		{
			cin>>boy[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>girl[i];
		}
		if(m>n)
			cout<<"NO"<<endl;
		else
		{
			bool flag=true;
			sort(boy,boy+m);
			sort(girl,girl+n);
			int j=0,i=0;
			while( i < m )
			{
				if( boy[i] > girl[j] )
					i++,j++;
				else 
				if( boy[i] <= girl[j] )
					{
						flag=false;
						cout<<"NO"<<endl;
					 	break;
					}
			}
			if(flag)
				cout<<"YES"<<endl;
		}
	}
}