#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int a[500][500];
bool visited[500][500];
bool last;
int tryIt(int x, int y)
{
	cout<<"x="<<x<<",y="<<y<<endl;
	visited[x][y] = true;
	if(y == m-1)
	{
		last = true;
		int val1 = 0, val2 = 0;
		for (int i = 0; i <= x; ++i)
		{
			val1+=a[i][y];
		}
		for (int i = x; i < n; ++i)
		{
			val2+=a[i][y];
		}

		return max(val2,val1);
	}
   	//cout<<"trying....."<<endl;
   	int sum = a[x][y];
	if(y+1 < m && !visited[x][y+1] && a[x][y+1]!=-1)
	{
		sum = sum+tryIt(x,y+1);
	}
	bool flag = false;
	int tempS = sum;
	if(x == n-1)
	{
		flag = true;
		x = -1;
		sum = 0;
	}
	if(a[x+1][y]!=-1 && !visited[x+1][y])
	{
		sum = sum+tryIt(x+1,y);
	}
	if(flag)
	{
		sum = tempS;
		x = n-1;
		flag = false;
	}
	if(x == 0)
	{
		flag = true;
		x = n;
		sum = 0;
	}
	if(a[x-1][y]!=-1 && !visited[x-1][y])
	{
		sum = sum+tryIt(x-1,y);
	}
	if(flag)
	{
		sum = tempS;
		x = 0;
		flag = false;
	}
	visited[x][y] = false;
	cout<<"x="<<x<<",y="<<y<<"="<<sum<<endl;
	return sum;
}

int main() {
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		cin>>a[i][j];
    	}
    }
    int maxi = 0;
    for (int i = n-1; i < n; ++i)
    {
    	if(a[i][0] != -1)
    	{
    		int val = tryIt(i,0);
    		maxi= max(maxi, val);
    	}
    	cout<<"maxi = "<<maxi<<endl;
    }
    if (last)
    {
    	int val = maxi;
    	for (int i = 0; i < n; ++i)
    	{
    		val+=a[i][m-1];
    	}
    	maxi = max(val,maxi);
    }
    cout<<"maxi = "<<maxi<<endl;
}