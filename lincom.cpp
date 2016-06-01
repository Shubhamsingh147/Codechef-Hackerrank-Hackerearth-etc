#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
int main()
{
	int m,n,r,a,b;
	cin>>m>>n;
	string arr[m];
	int count[m];
	for (int i = 0; i < m; ++i)
	{
		count[i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
			cin>>arr[i];
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(arr[i][j] - '0' == 1)
				count[i]++;
		}
	}
	cin>>r;
	for (int i = 0; i < r; ++i)
	{
		cin>>a>>b;
		a--;b--;
		if (arr[a][b] - '0' == 1)
		{
			arr[a][b] = '0';
			count[a] --;
		}
		else
		{
			arr[a][b] = '1';
			count[a] ++;
		}
	}
	int max = count[0];
	int winner = 0;
	for (int i = 1; i < m; ++i)
	{
		if (count[i] >= max)
		{
			max = count[i];
			winner = i;
		}
	}
	bool tie = false;
	for (int i = 0; i < m; ++i)
	{
		if (count[i] == max && i != winner)
		{
			tie  = true;
			break;
		}
	}
	if(tie)
		cout<<"Tie"<<endl;
	else
		cout<<winner+1<<endl;
}