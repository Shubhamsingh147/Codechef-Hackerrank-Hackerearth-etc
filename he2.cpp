#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,k,count=0;
	cin>>n>>k;
	int a[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	for( int i=1;i<n-1;i++)
	{
		for( int j=1;j<n-1;j++)
		{
			if( isPrime( a[i][j], a[i-1][j-1], a[i+1][j-1], a[i+1][j-1], a[i+1][j+1] ))
			{
				cout<<"yes"<<endl<<count<<endl<<i+1<<j+1<<endl;
			}
			else while()