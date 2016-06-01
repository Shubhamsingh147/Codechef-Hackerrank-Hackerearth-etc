#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		long long int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			sum += a[i];
		}
		if(sum == 0)
		{
			cout<<"0"<<endl;
			continue;
		}
		sort(a,a+n);
		long long int curr_sum = 0;
		int i;
		for (i = n-1; i >= 0; --i)
		{
			curr_sum += a[i];
			if(curr_sum > (sum - curr_sum) )
				break;
		}
		cout<<n-i<<endl;
	}
}
