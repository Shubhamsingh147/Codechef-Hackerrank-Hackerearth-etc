#include<iostream>
using namespace std;
int m, n;
int a[1000],b[1000],c[2000],c2[2000],d[1000][1000];

int binSearch(int x){
	
	int start = 0, end = m+n-1;
	int mid = (m+n-1)/2;
	while( c[mid]!= x && start <= end)
	{
		mid = (start + end)/2;
		if( x > c[mid] )
			start = mid + 1;
		else
			end = mid - 1;
	}
	return mid;
	}

int min(int i1, int i2){

	return i1>i2?i2:i1;
}

int mergeArrays(){
	
	int x=0,y=0;
	cout<<"Merged array\n";
	for (int i = 0; i < m+n; ++i)
	{
		if( a[x] <= b[y] && x < m)
			c[i] = a[x++], c2[i] = 1;
		else if( a[x] > b[y] && y < n)
			c[i] = b[y++], c2[i] = 2;
		else if(x == m)
			c[i] = b[y++], c2[i] = 2;
		else if(y == n)
			c[i] = a[x++], c2[i] = 1;
		cout<<c[i]<<"("<<c2[i]<<") ";
	}
	cout<<endl;
}

int makeGraph(){
	for (int i = 0; i < m+n; ++i)
	{
		for (int j = 0; j < m+n; ++j)
		{
			if(c[j] > c[i] && c2[j] != c2[i])
				d[i][j] = 1;
			else
				d[i][j] = 0;
		}
	}
	cout<<"Graph: \n";
	for (int i = 0; i < m+n; ++i)
	{
		for (int j = 0; j < m+n; ++j)
		{
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
}

void print(int x)
{
	for (int i = x+1; i < m+n; i++)
	{
		if(d[x][i] == 1)
		{
			cout<<c[i]<<"-";
			print(i);
		}
	}
	cout<<endl;
}

int main(){
	cin>>m>>n;
	
	for (int i = 0; i < m; ++i)
	{
		cin>>a[i];
	}
	int first = a[0], k = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>b[i];
	}
	if(b[n-1] < a[0])
		cout<<"No such!";
	else if(b[n-1] < a[0])
			cout<<a[0]<<" "<<a[0];
	
	mergeArrays();
	makeGraph();
	for (int i = 0; i < m; ++i)
	{
		cout<<"results for: "<<a[i]<<" at index: "<<binSearch(a[i])<<endl; 
		print(binSearch(a[i]));
	}
	
}
/* 4 7
5 8 12 14
2 6 7 9 10 11 13
*/