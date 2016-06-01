#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int t;
	int n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		long int sum = 0;
		for (int i = 0; i < n; ++i) 
		{
			cin>>a[i];
			sum += a[i];
		}
		if(sum % n != 0)
			cout<<"-1\n";
		else
		{
			long int eq = sum/n;
			int count = 0;
			for (int i = 0; i < n; ++i)
			{
				if(a[i] < eq)
					count += eq - a[i];
			}
			cout<<2*count<<endl;
		}
	}
}
