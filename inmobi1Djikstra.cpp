#include <iostream>
#include <limits.h>
using namespace std;
int n;
int a[10001][10001];
int findMin(int dist[], bool included[]){
	int min = INT_MAX;
	int minIndex = 1;
	for (int i = 1; i <= n; ++i)
	{
		if ( dist[i] <= min && !included[i] )
		{
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int main(){

	int m,x,y,z,s,n,d;
	cin>>m;
	n = INT_MIN;
	for (int i = 0; i < m; ++i)
	{
		cin>>x>>y>>z;
		n = max(n,max(x,y));
		if(a[x][y]!=0)
			a[x][y] = min(z,a[x][y]);
		else
			a[x][y] = z;
		a[y][x] = a[x][y];
	}
	int dist[n+1];
	bool included[n+1];
	cin>>s>>d;
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = INT_MAX;
		included[i] = false;
	}
	dist[s] = 0;
	included[s] = true;
	
	for (int i = 0; i < n-1; ++i)
	{
		int index = findMin(dist,included);
		included[index] = true;
		for (int j = 1; j <= n; ++j)
		{
			if (!included[j] && a[index][j] && (dist[index] != INT_MAX) && (dist[j] > (dist[index] + a[index][j])) )
				dist[j] = dist[index] + a[index][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if(dist[i] != INT_MAX)
			cout<<dist[i]<<endl;
		else
			cout<<"-1 ";
	}
	
}