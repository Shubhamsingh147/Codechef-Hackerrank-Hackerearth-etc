#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

long long int power(long long int x,long long int y)
{
	long long int ans=1;
	long long int square=x;
	if(y==0)
	    return 1;
	while(y!=0)
	{
	    if(y%2)
	        ans=ans*square;
	    square=(square*square)%1000000000;
	    y=y/2;
	    if(ans>1000000000)
	        ans=ans%1000000000;
	}
	return ans;
}
long long calcUtil(long long n)
{
	if(n==0||n==1||n==2)
		return 1;
	else if(n==3||n==4)
		return 3;
	else if(n==5||n==6)
		return 15;
	else if(n==7||n==8||n==9||n==10)
		return 105;
	else 
		{
			return static_cast<long long>( power(2 , ceil(n/4.0)) * calcUtil( ceil(n/5.0) ) * calcUtil( ceil(n/10.0) ) ) % 1000000000;
		}
}
long long int gcd(long long int a, long long int b)
{

    while(b) b ^= a ^= b ^= a %= b;
    return a;

}
long long int calc(long long n)
{
	long long int rn=calcUtil(n);
	if(rn==0)
		return 0;
	else
	{
		long long int ans=power(rn , rn);
		for(int k=2;k<=5;k++)
		{
			if(power(rn , k*rn) >= ans)
				ans=power(rn , k*rn);
			if(power(k*rn , rn) >= ans)
				ans=power(k*rn , rn);
		}
		if( gcd(2*rn , 3*rn )==rn)
		{
			if(power(2*rn , 3*rn) >= ans)
				ans=power(2*rn , 3*rn);
			if(power(3*rn , 2*rn) >= ans)
				ans=power(3*rn , 2*rn);
		}
		
		if( gcd(2*rn , 5*rn )==rn)
		{
			if(power(2*rn , 5*rn) >= ans)
				ans=power(2*rn , 5*rn);
			if(power(5*rn , 2*rn) >= ans)
				ans=power(5*rn , 2*rn);
		}
		if( gcd(3*rn , 5*rn )==rn)
		{
			if(power(3*rn , 5*rn) >= ans)
				ans=power(3*rn , 5*rn);
			if(power(5*rn , 3*rn) >= ans)
				ans=power(5*rn , 3*rn);
		}

		if( gcd(3*rn , 4*rn )==rn)
		{
			if(power(3*rn , 4*rn) >= ans)
				ans=power(3*rn , 4*rn);
			if(power(4*rn , 3*rn) >= ans)
				ans=power(4*rn , 3*rn);
		}
		if( gcd(4*rn , 5*rn )==rn)
		{
			if(power(4*rn , 5*rn) >= ans)
				ans=power(4*rn , 5*rn);
			if(power(5*rn , 4*rn) >= ans)
				ans=power(5*rn , 4*rn);
		}
		return ans;
	}
}
int main()
{
	int t;
	long long int n;
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		cout<<calc(n)<<endl;
	}
}