#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int min(int a, int b)
{
	return a>b?b:a;
}
	int main(){
		int t,n;
		cin>>t;
		while(t--)
		{
		cin>>n;
		int a[n][3];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		int dp[n+1][3];
		dp[0][0] = a[0][0];
		dp[0][1] = a[0][1];
		dp[0][2] = a[0][2];
		for (int i = 1; i < n; ++i)
		{
			dp[i][0] = min( a[i][0] + dp[i-1][1] , a[i][0] + dp[i-1][2] );

			dp[i][1] = min( a[i][1] + dp[i-1][0] , a[i][1] + dp[i-1][2] );

			dp[i][2] = min( a[i][2] + dp[i-1][0] , a[i][2] + dp[i-1][1] );
		}
		cout<<min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]))<<endl;
	}
}