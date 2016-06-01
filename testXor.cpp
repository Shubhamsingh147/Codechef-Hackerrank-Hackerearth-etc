#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
int main()
{
	long long int ans = 999999999999999;
	for (long long int i = ; i < 131; ++i)
	{
		ans = ans ^ i; 
	}
	cout<<ans;
}