#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
	long long int n,w;
	double min;
	cin>>n;
	double speed[n];
	long long fuel[n];
	double ans[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>speed[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>fuel[i];
	}
	cin>>w;
	
	min= (double)fuel[0]/speed[0];
	for (int i = 1; i < n; ++i)
	{
		ans[i] = fuel[i] / speed[i];
		if( min > ans[i] )
			min = ans[i];
	}
	std::cout << std::fixed;
	double final_ans= (double)w/(double)min;
	double b = final_ans;
	char s[20];
	for (int i = 0; i < 20; ++i)
	{
		s[i] = '-';
	}
	sprintf(s,"%f",b);
	int i = 0;
	while( s[i+4] != '-')
		cout<<s[i++];
}