#include <iostream>
#include <map>
using namespace std;
int main(){
	int t;
	long int n,k,m;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		int x[n];
		int c[n];
		int z[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>x[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin>>c[i];
		}
		for (int i = 0; i < k; ++i)
		{
			cin>>z[i];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(c[j] != 0)
				{
					if(!coPrime(x[i] , c[j]))
					{
						
					}
				}
			}
		}
	}