#include <iostream>
using namespace std;
long long int min(long long int a, long long int b) { return a>b?b:a; }
int main() {
	
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		long long int a[n];
		long long int sum = 0;
		for(int i = 0; i < n; i++)
		{
			cin>>a[i];
			sum += a[i];
		}
		long long int dp[100010];
		dp[0] = 0;
		dp[1] = 0;
		dp[2] = 0;
		dp[3] = min(a[1],a[3]);
		dp[4] = min(a[1], min( a[2]+a[3], a[3]+a[4] ));
		dp[5] = min(a[3]+a[4]+a[5], min( a[2]+a[3], (a[1] + min( a[3], a[5]))));

		for(int i = 6; i < n; i++)
		{
			long long int a1 = dp[i-6] + a[i-4] + min(a[i-2], a[i]);
			long long int b2 = dp[i-6] + a[i-3] + a[i-2];
			long long int c3 = dp[i-6] + a[i-2] + a[i-1] + a[i];
			dp[i] = min(a1, min(b2, c3));
		}
		cout<<sum - dp[n-1]<<endl	;
	}

	return 0;
}