#include <iostream>
using namespace std;
int dp[10001][10001];
int main(){
	int n,m;
	int t;
	for (int i = 0; i <= 10000; ++i)
	{
		dp[i][0] = 1;
		dp[i][1] = 1;
		dp[1][i] = 1;
	}
	for(int i=2;i<=10000;i++){
		for(int j=2;j<=10000;j++){
			for (int k = i; k <= j; k=k*i){
				dp[i][j] += dp[i][j-k];
			}
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=10;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cin>>t;
	while(t--){
		cin>>n>>m;
		cout<<dp[m][n]<<endl;
	}
}