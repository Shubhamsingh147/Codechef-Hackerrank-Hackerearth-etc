#include<iostream>
using namespace std;
int main()
{
	long int n,m,ans;
	cin>>n>>m;
	long int k = (n*(n+1))/2;
	if( m <= n) 
		ans = 1;
	else if(k < m) 
		ans = -1;
	else
	{
		ans = 0;
		while( m > n)
		{
			m = m - n;
			n--;
			ans++;
		}
		ans++;
	}
	cout<<ans<<endl;
}