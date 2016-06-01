#include <iostream>
using namespace std;
int main()
{
	long int n,k,ans=0;
	cin>>n;
	long int a[n];
	cin>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		if(a[i]<=k)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[i]*a[j]<=k)
				{
					for(int m=j+1;m<n;m++)
					{
						if(a[i]*a[j]*a[m]<=k)
							ans++;
					}	
				}
				else
					continue;
			}
		}
		else
			continue;
		
	}
	cout<<ans<<endl;
}