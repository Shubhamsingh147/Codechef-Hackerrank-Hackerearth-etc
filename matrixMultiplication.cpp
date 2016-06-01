#include <iostream>
using namespace std;
int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	int a[x][y],b[y][z],c[x][z];
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < z; ++j)
		{
			c[i][j] = 0;
		}
	}
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			cin>>a[i][j];
		}
	}
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < z; ++j)
		{
			cin>>b[i][j];
		}
	}
	for (int i = 0; i < x; ++i)
	{
		for (int k = 0; k < z; ++k)
		{
			for (int j = 0; j < y; ++j)
			{
				c[i][k] += a[i][j] * b[j][k]; 
			}
		}
	}
	cout<<endl;
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < z; ++j)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
}
/*
	1 2 3 4			1 2 3 4 5
	2 3 4 5   *     2 3 4 5 6
	3 4 5 6			3 4 5 6 7
					4 5 6 7 8