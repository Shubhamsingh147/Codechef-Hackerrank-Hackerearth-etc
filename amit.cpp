#include <iostream>
using namespace std;
int main()
{
	int t,x,ans,rem;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>x;
		if(x==1)
			cout<<"-1"<<endl;
		else
		{
			ans=x/7;
			rem=x%7;
			switch(rem)
			{
				case 0:
					cout<<ans<<endl;
					break;
				case 1:
					cout<<ans+1<<endl;
					break;
				case 2:
					cout<<ans+1<<endl;
					break;
				case 3:
					cout<<ans+1<<endl;
					break;
				case 4:
					cout<<ans+2<<endl;
					break;
				case 5:
					cout<<ans+1<<endl;
					break;
				case 6:
					cout<<ans+2<<endl;
					break;
			}
		}
	}
}