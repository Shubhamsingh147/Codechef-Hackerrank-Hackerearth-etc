#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int b[100000];
bool a[220001];
int k;
void generatePrimes(){
	a[1] = false;
	for(int i = 2; i <= sqrt(220000); ++i)
	{
		for(int j = 2*i; j <= 220000; j+=i)
		{
			a[j] = false;
		}
	}
	k = 1;
	for (int i = 1; i <= 220000; ++i)
		if(a[i])
			b[k++] = i;
}
int find(int x){
		int start = 1;
		int end = k;
		int mid = (end + start)/2;
		while(b[mid]!= x && start < end)
		{
			if(b[mid] > x)
				end = mid -1;
			else
				start = mid +1;
			mid = (start+end)/2;
		}
		cout<<"mid = "<<mid<<endl;
		if(b[mid] == x)
			return mid;
		else
			return mid + (x > b[mid]? 0 : -1);
		
}
int main(){
	
	for (int i = 0; i <= 220000; ++i)
		a[i] = true;
	generatePrimes();
	int dp[42] = {0};
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	for (int i = 5; i <= 40; ++i)
	{
		dp[i] = dp[i-1] + dp[i-4];
	}
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		//cout<<dp[n]<<endl;
		int ans = find(dp[n]);
		if(ans < 0)
			ans = 0; 
		cout<<ans<<endl;
	}    
    return 0;
}
