#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v;
		v.push_back(0);
		v.push_back(1);
		vector<int>::iterator it=v.end();
		vector<int>::iterator prev=v.begin();	
		do
		{
			v.push_back((*it)+(*prev));
			it++;prev++;
		}while((*it)<=2*n);

		it=v.begin();
		cout<<*it<<endl;
	}
	return 0;
}
