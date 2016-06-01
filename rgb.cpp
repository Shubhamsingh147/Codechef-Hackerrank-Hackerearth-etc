#include <iostream>
using namespace std;
int main()
{
	long long int t,r,g,b;
	cin>>t;
	while(t--)
	{
		cin>>r>>g>>b;
		long long int f,s,t,ans = 0,sum = 0;
		f = max(r, max(g,b));
		t = min(r, min(g,b));
		sum = r+g+b;
		s = sum - (f+t);
		if(f == s)
		{
			ans += sum/3;
		}
		else if(s == t)
		{
			//sum = f+s+t;
			if(f > 4*t)
				ans += 2*t;
			else
				ans += (sum/3);
		}
		else if(f > 2*s -t) // s comes down to t faster than f to s
		{
			f -= 2*(s-t);
			ans += (s-t);
			s = t;
			sum = f+s+t;
			if(f > 4*t)
				ans += 2*t;
			else
				ans += (sum/3);
		}
		else if(f < 2*s - t) // f comes down to s faster than s to t
		{
			ans += (f-s);
			f = 2*s - f;
			s = f;
			long long int sub = (s-t)/3;
			ans += sub * 2;
			s -= sub * 3;
			f -= sub * 3;
			sum = f+s+t;
			ans += sum/3;
		}
		else // all become equal together
		{
			sum = f+s+t;
			ans += (sum/3);
		}
		cout<<ans<<endl;
	}
}