#include<iostream>
#include<cmath>

using namespace std;
int main()
{
	int t;
	long double n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		double x = ceil((n-2)/2);
		if(n == 1)
			cout<<"1"<<endl;
		else
			cout<<x+2<<endl;
	}
	return 0;
}