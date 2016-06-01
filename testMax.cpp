#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

long int maximum(long int a, long int b)
{
	return a>b ? a : b;
}
int main()
{
	short t=32000;
	for (int i = 0; i < 1000; i*=2)
	{
		short p=t+i;
		cout<<p<<endl;
	}
}
	
