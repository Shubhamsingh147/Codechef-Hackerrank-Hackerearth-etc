#include <iostream>
using namespace std;

int main()
{
	int t,m,n,g,h,u,v,w,x,good,great;
	cin>>t;
	while(t--){
		cin>>m>>n;
		int a[10000] = {0};
		good = 0;
		great = 0;
		for (int i = 0; i < m; ++i)
		{
			cin>>u>>v;
			a[u] = v;
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>w>>x;
			if( a[w] )
			{
				good++;
				if( a[w] == x )
					great++;
				a[w] = 0;
			}
		}
		cin>>g>>h;
		if(good >= g)
		{
			if(great >= h)
			{
				cout<<"Great"<<endl;
				continue;
			}
			else
				cout<<"Good"<<endl;
		}
		else
			cout<<":("<<endl;
	}
}