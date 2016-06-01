#include <iostream>
#include <stdlib.h>
using namespace std;

long int min(long long int a, long long int b)
{
	return a > b ? b : a;
}

int main()
{
	bool flag = true;
	long int a,b,c;
	long int num[1001], Mnum[1001];
	cin>>num[1]>>num[2]>>num[3];
	cin>>a>>b>>c;
	Mnum[1] = num[1];
	Mnum[2] = min(num[1], num[2]);
	if (Mnum[2] != Mnum[1])
	{
		cout<<Mnum[1];
		flag = false;
	}
	Mnum[3] = min( num[1], min(num[2], num[3]) );
	if (Mnum[3] != Mnum[2])
	{
		cout<<Mnum[2];
		flag = false;
	}
	for (int i = 4; i < 1001; ++i)
	{
		num[i]= a*num[i-1] + b*num[i-2] + c* num[i-3];
		Mnum[i] = min( Mnum[i-1] , num[i]);
		if (Mnum[i] != Mnum[i-1])
		{
			cout<<Mnum[i-1];
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout<<Mnum[1];	
	}
}