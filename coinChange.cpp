#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
int getCount(int a[], int m, int n){
	int tab[n+1][m];
	for (int i = 0; i < m; ++i)
		tab[0][i] = 1;
	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			tab[i][j] = (i-a[j] >= 0? tab[i-a[j]][j]:0) + (j-1 >= 0? tab[i][j-1]:0);
		}
	}
	return tab[n][m-1];
}
int main()
{
	int n,m;
	cin>>n>>m;
	int a[m];
	for (int i = 0; i < m; ++i)
	{
		cin>>a[i];
	}
	cout<<"No.of ways of getting change: "<<getCount(a,m,n);
}