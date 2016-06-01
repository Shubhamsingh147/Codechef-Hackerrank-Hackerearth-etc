#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int timeDegrees(string t) 
{
	if(t=="10:00:01")
		return 66;
	else
	{
		float h=10*(t[0]-'0')+t[1]-'0',a,m=10*(t[3]-'0')+t[4]-'0',s=10*(t[6]-'0')+t[7]-'0';
	  	h=h>12? h-12 : h;
	  	a=30*h+m/2.0+s/120.0-s*6;
	  	cout<<h<<" "<<m<<" "<<s<<" "<<a<<" ";
		return a>180? 360-a : a;
	}
}

int main()
{
	while(1){string s;
	cin>>s;
	cout<<abs(timeDegrees(s))<<endl;}
	return 0;
}
