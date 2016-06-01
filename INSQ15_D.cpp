#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
int main(){
	int n,k;
	string s;
	cin>>n>>k;
	cin>>s;
	char a[n/k][k];
	int x = 0;
	for (int i = 0; i < n; i+=k)
	{
		for (int j = 0; j < k; ++j)
		{
			a[x][j]= s[i+j];
		}
		x++;
	}

	// for (int i = 0; i < n/k; ++i)
	// {
	// 	for (int j = 0; j < k; ++j)
	// 	{
	// 		cout<<a[i][j];
	// 	}
	// 	cout<<endl;
	// }
	char ans[n/k];
	for (int i = 0; i < k; ++i)
	{
		int alpha[3] = {0};
		for (int j = 0; j < n/k; ++j)
		{
			alpha[a[j][i] - 'a']++;
		}
		int maxi = max(alpha[0], max(alpha[1], alpha[2]));
		if(maxi == alpha[0])
			ans[i] = 'a';
		else if(maxi == alpha[1])
			ans[i] = 'b';
		else if(maxi == alpha[2])
			ans[i] = 'c';
	}
	for (int i = 0; i < k; ++i)
	{
		cout<<ans[i];
	}
	cout<<endl;
}