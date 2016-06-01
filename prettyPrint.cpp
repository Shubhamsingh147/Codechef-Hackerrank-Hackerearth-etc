#include <iostream>
#include <vector>
using namespace std;

void fill(int n, vector<vector<int> > &v)
{
	for (int j = (v.size()/2)-n+1; j < v.size() - ((v.size()+1)/2 - n ); ++j)
	{
		v[(v.size()/2)-n+1][j] = n;
		v[v.size() - ((v.size()+1)/2 - n + 1)][j] = n;
	}
	for (int i = (v.size()/2)-n+1; i < v.size() - ((v.size()+1)/2 - n ); ++i)
	{
		v[i][(v.size()/2)-n+1] = n;
		v[i][v.size() - ((v.size()+1)/2 - n + 1)] = n;
	}
}
void make(int a)
{
	vector<vector<int> > v(2*a-1,vector<int>(2*a-1));
	for (int i = a; i >= 1; --i)
	{
		fill(i,v);
	}
	for (int i = 0; i < 2*a-1; ++i)
	{
		for (int j = 0; j < 2*a-1; ++j)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int a;
	cin>>a;
	make(a);
}