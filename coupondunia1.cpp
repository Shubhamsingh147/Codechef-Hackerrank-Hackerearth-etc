#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	int t;
	long long l,r,sqrt_l,sqrt_r,ans;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>l>>r;
		sqrt_l = sqrt(l);
		sqrt_r = sqrt(r);
		if (sqrt_l * sqrt_l == l && sqrt_r * sqrt_r == r)
			ans = 1 + sqrt_r - sqrt_l ;
		else
			if (sqrt_l * sqrt_l == l)
				ans = 1 + sqrt_r - sqrt_l ;
		else
			ans = sqrt_r - sqrt_l ;
		cout<<ans<<endl;
	}
}