#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	long long int max_till_now=0, max_this_time=0,m;
	cin>>n>>m;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	for (int i = 1; i < n; ++i)
	{
		if(max_this_time > max_till_now && max_this_time <= m)
		{
			max_till_now = max_this_time;
		}
	}
	cout<<max_till_now<<endl;
}