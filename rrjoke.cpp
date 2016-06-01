#include<iostream>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	int h[121];
	h[0]=0;
	for(int i=1;i<121;i++)
	{
		h[i]=h[i-1]^i;
	}
	while(t--)
	{
		cin>>n;
		int x[40],y[40];
		for(int i=0;i<n;i++)
			cin>>x[i]>>y[i];
		cout<<h[n]<<endl;
	}

}