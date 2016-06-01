#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	long long int dp[1000000];
	dp[1] = 1;
	dp[2] = 2;
	long long int x;
	for (int i = 3; i <= 1000000 ; ++i)
	{
		x = dp[i-1] + (dp[i-2]*(i-1));
		dp[i] = x > 1000000007? x%1000000007 : x;
	}
	while(t--)
	{
		cin>>n;
		cout<<dp[n]<<endl;
	}
}