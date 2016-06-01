#include <iostream>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		long int sum = 0;
		for(int i = 0 ; i < n ; i++)
		{
			cin>>a[i];
			sum += a[i];
		}
		if(sum != 0 && sum % n == 0 )
		{
			cout<<sum/n<<endl;
		}
		else
			cout<<"-1"<<endl;
	}
}