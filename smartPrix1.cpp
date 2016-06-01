#include<bits/stdc++.h>
using namespace std;
int modPow(int x,int y,int z){
	int a = x % z;
	int t = 1;
	while( y > 0 )
	{
		if( y % 2 == 1 )
		{
			t = (t * a) % z;
		}
		y /= 2;
		a = (a * a) % z;
	}
	return(t);
}
int main()
{
vector<int> v;
string str;
int num=0;
	
	for(int i=0;i<3;i++)
	{
	cin>>str;
	num=0;
		for(int j=0;j<str.size()-1;j++)
		{
			num*=10;
			num+=(str[j]-'0');
		}
		v.push_back(num);

	}
	int a=v[0],b=v[1],c=v[2],k=a;
	c*=10;
	c+=(str[str.size()-1]-'0');
	cout<<modPow(a,b,c)<<endl;
}