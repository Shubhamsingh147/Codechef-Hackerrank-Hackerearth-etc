#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int t,x,y,n,k,req;
	bool flag;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d%d",&x,&y,&k,&n);
		//cin>>x>>y>>k>>n;
		int p[n],c[n];
		req=x-y;
		flag=false;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d",&p[i],&c[i]);
			//cin>>p[i]>>c[i];
			if (req <= p[i] && c[i] <= k)
				flag=true;
		}
		if(flag)
			cout<<"LuckyChef\n";
		else 
			cout<<"UnluckyChef\n";
	}
}