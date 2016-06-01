#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
int main()
{
	int t;
	long long int m,n;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		if( m == n)
			cout<<"0"<<endl;
		else
		{
			int x = ceil(log2(m));
			int y = floor(log2(n));
			cout<<"x = "<<x<<" y = "<<y<<endl;
			long long int ans = m;
			long long int x_2 = 1<<x;
			long long int y_2 = 1<<y;
			if(x_2 == m && y_2 == n)
				cout<<y_2<<endl;
			else if( x_2 == m && y_2!=n)
			{
				ans = y_2;
				for (long long int i = y_2+1; i <= n; ++i)
				{
					ans = ans ^ i;
				}
				cout<<ans<<endl;
			}
			else if( x_2 !=m && y_2 == n)
			{
				ans = m;
				for (long long int i = m+1; i < x_2; ++i)
				{
					ans = ans ^ i;
				}
				ans = ans ^ y_2;
				cout<<ans<<endl;
			}
			else
			{
				//cout<<"numbers between "<<x_2<<" and "<<y_2<<endl;
				for (long long int i = m+1; i < x_2 && i <= n; ++i)
				{
					cout<<"xorring"<<endl;
					ans = ans ^ i;
				}
				if(n > y_2 && y_2 > x_2)
					ans = ans ^ y_2;
				if(y_2 > x_2 && y_2 > m && n > y_2)
					for (long long int i = y_2+1; i <= n; ++i)
					{
						ans = ans ^ i;
					}

				cout<<ans<<endl;
			}
		}
	}
}