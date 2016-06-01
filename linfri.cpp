#include <iostream>
#include <cmath>

using namespace std;

long long int max(long long int a, long long int b){
	return a>b? a:b;
}
int main()
{
	int t;
	int n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int a[n];
		for (int i = 0; i < n; ++i) 
		{
			cin>>a[i];
		}
		long long int ans[n];
		ans[0] = a[0];
		ans[1] = max( ans[0], a[1] );
		for (int i = 2; i < n; ++i)
		{
			ans[i] = max( ans[i-2] + a[i] , ans[i-1]);
		}
		cout<<ans[n-1]<<endl;
	}
}