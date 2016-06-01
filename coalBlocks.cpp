#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n,k,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		vector<int> a;
		int x;
		for (int i = 0; i < n; ++i)
		{
			cin>>x;
			a.push_back(x);
		}
		if(n==1)
		{
			cout<<"1\n";
			continue;
		}
		int count = 0;
		while(a.size())
		{
			count++;
			int temp = 0;
			for (int i = 1; i < a.size(); ++i)
			{
				if(abs(a[temp]-a[i]) >= k)
				{
					//cout<<"deleting"<<a[temp]<<"in pass"<<count<<endl;
					a.erase(a.begin()+temp);
					i--;
					temp = i;
				}
			}
			//cout<<"deleting"<<a[temp]<<"in pass"<<count<<endl;
			a.erase(a.begin()+temp);
		}
		cout<<count<<endl;
	}
}