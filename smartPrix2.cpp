#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> x,y;
	string str;
	int num=0;
	for(int i=0;i<8;i++)
	{
	num=0;
	int j=1;
	cin>>str;
		for(;str[j]!=',';j++)
		{
			num*=10;num+=(str[j]-'0');
		}
		x.push_back(num);
		j++;
		num=0;
		for(;str[j]!=')';j++)
		{
			num*=10;num+=(str[j]-'0');
		}
		y.push_back(num);
	}
}