#include <iostream>

#include <string.h>
#include <vector>
#include <math.h>
#define ll long long
using namespace std;
int dp[10000][10000];
int main()
{
	int t;
	cin>>t;
	// for (int m = 5; m <= 5; ++m)
	// {
	// 	for (int n = 24; n <= 126; ++n)
	while(t--)
 	{
		long int n,m;
		long int count=0,k=0;
		cin>>n>>m;
		std::vector<int> v;
		if(m == 1 || n == 0)
		{
			cout<<"1\n";
			continue;
		}
		while(pow(m,k)<=n)
		{
			v.push_back(pow(m,k));
			k++;
		}
		memset(dp,0,sizeof(dp[0][0])*k*(n+1));
		for (int i = 0; i <=n; ++i)
		{
			if(i<k)
				dp[i][0]=0;
			dp[0][i]=1;
		}
		dp[0][0]=0;
		for (int i = 1; i < k; ++i)
		{
			for (int j=1;j<=n; ++j)
			{
				if(j<v[i])
					dp[i][j]=dp[i-1][j];
				else if(j%v[i]==0)
					dp[i][j]=1+max(dp[i][j-1],dp[i-1][j]+dp[i-1][j-v[i]]);
				else
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]+dp[i-1][j-v[i]]);
			}
		}
		cout<<dp[k-1][n]<<endl;
	}
	return 0;
}