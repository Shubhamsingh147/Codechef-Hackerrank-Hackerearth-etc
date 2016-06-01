#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
string s;
long int a[1000000],dp[1000000];
long int maximum(long int a, long int b)
{
	return a>b ? a : b;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		long int l= s.length();
		long int max=0;
		long int count=0;
		for (long int i = 0; i < l; ++i)
		{
			count+= (s[i] == 'R') ? 1 : 0;
			a[i] = (s[i] == 'R') ? -1 : 1;		
		}
		max=dp[0]=a[0];
		for (int i = 1; i < l; ++i)
		{
			dp[i]=maximum( a[i], a[i]+dp[i-1]);
			max=maximum( dp[i], max );
		}
		cout<<max+count<<endl;
	}
}