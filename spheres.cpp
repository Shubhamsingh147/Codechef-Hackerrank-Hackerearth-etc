#include <iostream>
#include <stdio.h>
#define mod 1000000007
using namespace std;
int main()
{
	int n,m,c;
	cin>>n>>m>>c;
	int a[n];
	int b[m];
	int nums1[1002] = {0};
	int nums2[1002] = {0};
	int ways[1002] = {0};
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	for (int i = 0; i < m; ++i)
		cin>>b[i];	
	for (int i = 0; i < n; ++i)
		nums1[a[i]]++;
	for (int i = 0; i < m; ++i)
		nums2[b[i]]++;
	long long int count = 0;
	long long int sum = 0;
	for (int i = 1; i < 1001; ++i)
	{
		ways[i] = (nums1[i] * nums2[i])%mod;
		sum += ways[i];
	}

	long long int prod = 1;
	for (int i = 1; i <= c; ++i)
	{
		while
		p/=i>1? ways[i-1]:1;
		p *= ways[i];
		sum -= ways[i];
		count += (sum-ways[i])*p;
	}
}