#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int m,n;
bool isSafe(int i, int j)
{
	return ( 0 <= i && i < m && j >= 0 && n > j);
}
int main()
{
	int q,x,y,d;
	cin>>m>>n>>q;
	int a[m][n];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>a[i][j];
		}
	}
	while(q--)
	{

		int colour[m][n];
		cin>>x>>y>>d;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				colour[i][j] = 0;
		queue<pair<int,int>> kyu;
		kyu.push(make_pair(x-1,y-1));
		colour[x-1][y-1] = 1;
		while(!kyu.empty())
		{
			pair<int, int> top = kyu.front();
			kyu.pop();
			int i = top.first;
			int j = top.second;
			if( isSafe(i+1,j) && !colour[i+1][j] && abs(a[i][j] - a[i+1][j]) <= d)
			{
				colour[i+1][j] = 1;
				kyu.push(make_pair(i+1,j));
			}
			if( isSafe(i-1,j) && !colour[i-1][j] && abs(a[i][j] - a[i-1][j]) <= d)
			{
				colour[i-1][j] = 1;
				kyu.push(make_pair(i-1,j));
			}
			if( isSafe(i,j+1) && !colour[i][j+1] && abs(a[i][j] - a[i][j+1]) <= d)
			{
				colour[i][j+1] = 1;
				kyu.push(make_pair(i,j+1));
			}
			if( isSafe(i,j-1) && !colour[i][j-1] && abs(a[i][j] - a[i][j-1]) <= d)
			{
				colour[i][j-1] = 1;
				kyu.push(make_pair(i,j-1));
			}
		}
		int count = 0;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if(colour[i][j])
					count++;
		cout<<count<<endl;
	}
}