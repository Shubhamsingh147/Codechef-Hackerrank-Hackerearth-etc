#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		std::vector<pair<int,int> > v;
		cin>>n;
		int a[n][n];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>a[i][j];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				int count=0;
				for (int k = 0; k < n; ++k)
				{
					if( k!=i && k!=j )
					{
						if( a[i][k] + a[k][j] == a[i][j] )
							break;
						else
							count++;
					}
				}
				if( count == n-2 )
					v.push_back(make_pair(i,j));
			}
		}
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v.at(i).first+1<<" "<<v.at(i).second+1<<endl;
		}
		cout<<endl;
	}
}