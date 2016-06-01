#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		string s;
		cin>>s;
		int count=1,flip=0;
		for (int i = 1; i < n; ++i)
		{
			if (s[i] != s[i-1])
				count = 1;
			else count++;
			if (count > k)
			{
				s[i] = (s[i] == '1')? '0' : '1';
				flip++;
				count = 1;
			}
		}
		cout<<flip<<endl<<s<<endl;
	}
}