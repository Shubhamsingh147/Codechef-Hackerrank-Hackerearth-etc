#include <iostream>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+1];
		for (int i = 1; i <= n; ++i)
		{
			cin>>a[i];
		}
		long long int sum = 0,max = 0;	
		for (int i = 2; i <= n; ++i)
		{
			sum = 0;
			for (int j = i; j <= n; j += i)
			{
				sum += a[j];
			}
			if(max < sum)
				max = sum;
		}
		cout<<max<<endl;
	}
}