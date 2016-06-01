#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	long r,k,v;
	cin>>t;
	while(t--)
	{
		vector<long> vec;
		cin>>r>>k>>v;
		if ( r == 0 && k == 0 && v ==0 )
			cout<<"0"<<endl;
		else
		{
			vec.push_back(r);
			vec.push_back(k);
			vec.push_back(v);
			sort(vec.begin(), vec.end());
			if ( vec.at(1) == vec.at(2) )
				cout<< vec.at(1)*2 <<endl;
			else
				cout<< vec.at(1)*2 + 1 <<endl;			
		}

	}
}