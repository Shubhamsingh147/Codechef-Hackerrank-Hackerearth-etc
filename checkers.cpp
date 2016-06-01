#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	char a[n][m];
	bool exists[n][m];
	bool possible[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			possible[i][j] = true;
		}
	}
	char c1 = 'd';
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
			exists[i][j] = false;
			// if(possible[i][j])
			// {
			// 	if((j-1 >= 0 && a[i][j-1] == a[i][j]) )
			// 	{
			// 		for (int x = j; x >= 0 && x > j - 32 ; --x)
			// 		{
			// 			for (int y = i; y >= 0 && y > i - 32; --y)
			// 				possible[x][y] = false;
			// 			for (int y = i; y < n && y < i + 32; ++y)
			// 				possible[x][y] = false;
			// 		}
			// 		for (int x = j - 1; x < n && x < j + 32 -1 ; x++)
			// 		{
			// 			for (int y = i; y >= 0 && y > i - 32; --y)
			// 				possible[x][y] = false;
			// 			for (int y = i; y < n && y < i + 32; ++y)
			// 				possible[x][y] = false;
			// 		}
			// 	}
			// 	else if( i-1 >= 0 && a[i-1][j] == a[i][j] )
			// 	{
			// 		for (int x = j; x >= 0 && x > j - 32 ; --x)
			// 		{
			// 			for (int y = i; y >= 0 && y > i - 32; --y)
			// 				possible[x][y] = false;
			// 			for (int y = i-1; y < n && y < i + 32 - 1; ++y)
			// 				possible[x][y] = false;
			// 		}
			// 		for (int x = j; x < n && x < j + 32 ; x++)
			// 		{
			// 			for (int y = i; y >= 0 && y > i - 32; --y)
			// 				possible[x][y] = false;
			// 			for (int y = i - 1; y < n && y < i + 32 - 1; ++y)
			// 				possible[x][y] = false;
			// 		}
			// 	}
			// }
		}
	}
	int count = 0;

	for (int i = 0; i <= n - 32; ++i)
	{
		for (int j = 0; j <= m - 32; ++j)
		{
			if( j-2 >= 0 && exists[i][j-2] ){
				int xs = i, ys = j;
				bool flag = true;
				for (int k = i ; k < i + 32 && k < n; ++k)
				{
					for (int l = j + 30; l < j + 32 && l < m; ++l)
					{
						if((a[k][l] != '#' && (k-xs + l-ys)%2 == 1) || (a[k][l] != '_' && (k-xs + l-ys)%2 == 0)){
							flag = false;

							break;
						}
					}
					if(!flag)
						break;
				}
				if(flag){
					count++;
					exists[i][j] = true;
				}
			}
			else if( i-2 >= 0 && exists[i-2][j] ){
				int xs = i, ys = j;
				bool flag = true;
				for (int k = i + 30; k < i + 32 && k < n; ++k)
				{
					for (int l = j; l < j + 32 && l < m; ++l)
					{
						if((a[k][l] != '#' && (k-xs + l-ys)%2 == 1) || (a[k][l] != '_' && (k-xs + l-ys)%2 == 0)){
							flag = false;
							break;
						}
					}
					if(!flag)
						break;
				}
				if(flag){
					count++;
					exists[i][j] = true;
				}
			}
			else if( j-2 >= 0 && i-2 >= 0 && exists[i-2][j-2] ){
				int xs = i, ys = j;
				bool flag1 = true, flag2 = true;
				for (int k = i + 30; k < i + 32 && k < n; ++k)
				{
					for (int l = j; l < j + 32 && l < m; ++l)
					{
						if((a[k][l] != '#' && (k-xs + l-ys)%2 == 1) || (a[k][l] != '_' && (k-xs + l-ys)%2 == 0)){
							flag1 = false;
							break;
						}
					}
					if(!flag1)
						break;
				}
				for (int k = i ; k < i + 32 && k < n; ++k)
				{
					for (int l = j + 30; l < j + 32 && l < m; ++l)
					{
						if((a[k][l] != '#' && (k-xs + l-ys)%2 == 1) || (a[k][l] != '_' && (k-xs + l-ys)%2 == 0)){
							flag2 = false;
							break;
						}
					}
					if(!flag2)
						break;
				}
				if(flag1 && flag2){
					count++;
					exists[i][j] = true;
				}
			}
			else if(a[i][j] == '_')
			{
				int xs = i, ys = j;
				bool flag = true;
				for (int k = i; k < i + 32 && k < n; ++k)
				{
					for (int l = j; l < j + 32 && l < m; ++l)
					{
						if((a[k][l] != '#' && (k-xs + l-ys)%2 == 1) || (a[k][l] != '_' && (k-xs + l-ys)%2 == 0)){
							flag = false;
							break;
						}
					}
					if(!flag)
						break;
				}
				if(flag){
					count++;
					exists[i][j] = true;
				}
			}
		}
	}
	cout<<count;
}