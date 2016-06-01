#include <iostream>
#include <vector>
#include <string>
using namespace std;

char a[][3]={{'R', '.', 'R'},
			 {'.', '.', '.'},
			 {'R', '.', 'R'}};
int n,count=0;
void traverse(int i, int j, int dir , int n=3)
{
	count++;
	switch(dir)
	{
		case 0: cout<<i<<","<<j<<"-"<<dir<<endl;
				if(a[i-1][j] == 'R' && n > i-1 >= 0 )
					traverse(i-1,j,1);
				if(a[i-1][j] == 'L' && n > i-1 >= 0 )
					traverse(i-1,j,3);
				if(a[i-1][j] == '.' && n > i-1 >= 0 )
					traverse(i-1,j,dir);
				break;
		case 1: cout<<i<<","<<j<<"-"<<dir<<endl;
				if(a[i][j+1] == 'R' && n > j+1 >= 0 )
					traverse(i,j+1,2);
				if(a[i][j+1] == 'L' && n > j+1 >= 0 )
					traverse(i,j+1,0);
				if(a[i][j+1] == '.' && n > j+1 >= 0 )
					traverse(i,j+1,dir);
				break;
		case 2: cout<<i<<","<<j<<"-"<<dir<<endl;
				if(a[i+1][j] == 'R' && n > i+1 >= 0 )
					traverse(i+1,j,3);
				if(a[i+1][j] == 'L' && n > i+1 >= 0 )
					traverse(i+1,j,1);
				if(a[i+1][j] == '.' && n > i+1 >= 0 )
					traverse(i+1,j,dir);
				break;
		case 3:
				cout<<i<<","<<j<<"-"<<dir<<endl;
				if(a[i][j-1] == 'R' && n > j-1 >= 0 )
					traverse(i,j-1,0);
				if(a[i][j-1] == 'L' && n > j-1 >= 0 )
					traverse(i,j-1,2);
				if(a[i][j-1] == '.' && n > j-1 >= 0 )
					traverse(i,j-1,dir);
				break;
	}
}

int main()
{
	int max=0;
	n=3;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(a[i][j]=='.')
			{
				//0=north, 1=right, 2=south, 3=left
				cout<<"New Traversal Start at"<<i<<","<<j<<endl;
				for (int k = 0; k < 4; ++k)
				{
					traverse(i,j,k); 
					cout<<"count="<<count<<endl;
					if(count>max) 
						max = count;
					count=0;
				}
			}
			
		}
	}
	cout<<"max="<<max<<endl;
}