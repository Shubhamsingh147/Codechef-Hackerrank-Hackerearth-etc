#include <iostream>
#include <stdlib.h>
using namespace std;

long long int min(long long int a, long long int b)
{
	return a > b ? b : a;
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int s[n];
		
		for (int i = 0; i < n; ++i)
		{
			cin>>s[i];
		}
		long long int answer=abs(s[0]-s[1]);
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				answer = min( answer, abs(s[i] - s[j]) );
			}
		}
		cout<<answer<<endl;
	}
}