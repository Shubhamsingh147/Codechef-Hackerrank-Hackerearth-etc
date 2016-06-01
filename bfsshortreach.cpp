#include <iostream>
#include <string.h>
using namespace std;
	
int main()
{
    int t;
    cin>>t;
    int e,v,s,x,y;
    while(t--)
    {
    	cin>>v>>e;
    	int a[v][v];
    	for (int i = 0; i < v; ++i)
    		for (int j = 0; j < v; ++j)
    			a[i][j] = 0;
    	
    	for (int i = 0; i < e; ++i)
    	{
    		cin>>x>>y;
    		a[x][y] = 1;
    		a[y][x] = 1;
    	}
    	cin>>s;
    	
	}
}