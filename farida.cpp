#include <iostream>
using namespace std;

int main() {
	
	int t,n;
	cin>>t;
	int cases = t;
	while(t--){
		cin>>n;
		if(n == 0)
		{
			cout<<"Case "<<cases - t<<": "<<"0"<<endl;
			continue;
		}
		long long int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		long long int dp[n];
		dp[0] = a[0];
		dp[1] = max(a[0],a[1]);
		for(int i = 2; i <n; i++)
		{
			dp[i] = max(dp[i-2]+a[i] , dp[i-1]);
		}
		cout<<"Case "<<cases - t<<": "<<dp[n-1]<<endl;
	}

	return 0;
}