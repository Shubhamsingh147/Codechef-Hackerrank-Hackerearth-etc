#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int main()
{
	int t;
	long n;
	scanf("%d",&t);
	while(t--)
	{
		long max = 0,index = 0;
		cin>>n;
		if(n==1)
		{
			cin>>max;
			cout<<"0"<<endl;
			continue;
		}
		else
		if (n == 2)
		{
			cin>>max>>index;
			cout<<"0"<<endl;
			continue;
		}
		long a[n];
		scanf("%ld",&a[0]); 
		scanf("%ld",&a[1]);
		for (int i = 2; i < n; ++i)
		{
			scanf("%ld",&a[i]);
			if ( ( abs(a[i-2] - a[i-1]) + abs(a[i] - a[i-1]) - abs(a[i] - a[i-2]) ) > max )
			{
				max = abs(a[i-2] - a[i-1]) + abs(a[i] - a[i-1]) - abs(a[i] - a[i-2]);
				index = i-1;
			}
		}
		if ( abs(a[n-1] - a[n-2]) > max )
			index = n-1;
		cout<<index<<endl;
	}
}