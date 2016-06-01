#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int m,n,count=0;
	pair<int,int> start,goal;
	pair<int,int> points[]
	cin>>m>>n;
	char a[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='G')
				end=make_pair(i,j);
			if(a[i][j]=='S')
				start=make_pair(i,j);
			if(a[i][j]=='@')
			{
				count++;
			}
		}
	}

}

/*
# # # #
# # . G
# @ . #
@ . . #
# @ . S
*/