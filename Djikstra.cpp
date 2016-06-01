#include <iostream>
#include <limits.h>
using namespace std;
int n;
int findMin(int dist[], bool included[]){
	int min = INT_MAX;
	int minIndex = 1;
	for (int i = 1; i <= n; ++i)
	{
		if ( dist[i] < min && !included[i] )
		{
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int m,x,y,z,s;
		cin>>n>>m;
		int a[n+1][n+1];
		int dist[n+1];
		bool included[n+1];
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				a[i][j] = 0;
			
		for (int i = 0; i < m; ++i)
		{
			cin>>x>>y>>z;
			if(a[x][y])
			{	a[x][y] = min(z,a[x][y]);
				a[y][x] = a[x][y];
			}
		}
		cin>>s;
		for (int i = 1; i <= n; ++i)
		{
			dist[i] = INT_MAX;
			included[i] = false;
		}
		dist[s] = 0;
		included[s] = true;
		for (int i = 1; i <= n; ++i)
		{
			int index = findMin(dist,included);

			included[index] = true;

			for (int j = 1; j <= n; ++j)
			{
				if (!included[j] && a[index][j] && (dist[j] > (dist[index] + a[i][j])) && (dist[index] != INT_MAX))
					dist[j] = dist[index] + a[i][j];
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			if(i != s)
			{
				if(dist[i] != INT_MAX
)
					cout<<dist[i]<<" ";
				else
					cout<<"-1 ";
			}
		}

	}
}