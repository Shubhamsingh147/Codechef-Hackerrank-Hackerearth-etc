#include <iostream>
#define mod 1000000007
using namespace std;
int dp[1001][1001];
int main()
{
	long long int t,n,k,m,ans;
	cin>>t;
	for (int i = 1; i <= 1000; ++i)
	{
		for (int j = i; j <= 1000; ++j)
		{
			if(i == j)
				dp[i][j] = 2;
			else if(j < 2*i)
				dp[i][j] = (dp[i][j-1] + 1)%mod;
			else
				dp[i][j] = (dp[i][j-1] + dp[i][j-i])%mod;
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}

	while(t--)
	{
		cin>>n>>k;
		cout<<dp[k][n]<<endl;
	}
}