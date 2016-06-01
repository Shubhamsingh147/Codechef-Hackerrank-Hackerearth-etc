#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[8][8];
void printIt()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{	
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void mark( int x, int y, int type )
{
	a[x][y] += type;
	int m=x,n=y;
	// vert and horiz
	for (int j = 0; j < 8; ++j)
	{
		if( j != y )
			a[x][j] += type;
		if(j != x)
			a[j][y] += type;
	}

	//diags
	if(m!=0 && n!=0)
	while( m >= 0 && n >= 0 )
	{
		a[m--][n--] += type;
	}
	
	m=x,n=y;
	if( m!=7 && n!=0 )
	while( m < 8 && n >= 0 )
	{
		if( m == x && n == y )
			m++,n--;
		else
			a[m++][n--] += type;
	}
	
	m=x,n=y;
	if(m!=0 && n!=7)
	while( m >= 0 && n < 8 )
	{
		if( m == x && n == y )
			m--,n++;
		else
			a[m--][n++] += type;
	}
	m=x,n=y;
	if(m!=7 && n!=7)
	while( m < 8 && n < 8 )
	{
		if( m == x && n == y )
			m++,n++;
		else
			a[m++][n++] = type;
	}
	printIt();	
}

bool isSolution( int x , int y , int queens)
{
	if( queens == 8)
	{	
		cout<<"\n8 queens placed Yeah!!\n";
		return true;
	}
	else cout<<"\n"<<queens<<" queens placed\n";
	int i,j;
	for (i = 0; i < 8; ++i)
	{
		for (j = 0; j < 8; ++j)
		{	
			if( !a[i][j] )
			{
				cout<<"\nmarking "<<i<<","<<j<<" ...\n";
				mark( i, j, 1);
				queens++;
				if(isSolution( i, j, 1))
					return true;
				else
				{
					cout<<"\nunmarking "<<i<<","<<j<<" ...\n";
					mark( i, j, -1 );
					queens--;
				}
			}
		}
	}
	if( i == 8 && j == 8 && queens != 8)
		return false;
}

int main()
{
	int count=0;
	
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			a[i][j]=0;
		}
	}
	for (int j = 0; j < 8; ++j)
	{
		if(isSolution( 0 , j , 0 ))
			count++;
		else
			a[0][j]=0;
	}	
}