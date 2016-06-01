#include <bits/stdc++.h>
using namespace std;
int main()
{
	int s;
	cin>>s;
	int n;
	cin>>n;
	int a[n+1];
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	bool dp[s+1][n+1];
	for (int i = 0; i <= n; ++i)
	{
		dp[0][i] = true;
	}
	for (int i = 0; i <= s; ++i)
	{
		dp[i][0] = false;
	}
	for (int i = 1; i <= s; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] = dp[i][j-1];
			if(i >= a[j])
				dp[i][j] = dp[i][j] || dp[i-a[j]][j-1];
		}
	}
	if(dp[s][n])
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}