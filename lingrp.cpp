#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int t;
	int m,n,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+1][n+1];
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				a[i][j] = 0;
			}
		}
		cin>>m;
		for (int i = 0; i < m; ++i)
		{
			cin>>x>>y;
			a[x][y] ++;
			a[y][x] ++;
		}
		int count_odd = 0;
		for (int i = 1; i <= n; ++i)
		{
			int count = 0;
			for (int j = 1; j <= n; ++j)
			{
				if (a[i][j] == 1)
				{
					count ++;
				}
			}
			if(count % 2 == 1)
				count_odd ++;
		}
		if(count_odd > 2)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
}