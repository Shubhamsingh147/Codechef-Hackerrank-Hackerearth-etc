#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int s;
	cin>>s;
	int l[s];
	for(int i=0;i<s;i++)
		cin>>l[i];
	sort(l,l+s);
	for(int j=0;j<s;j++)
		cout<<l[j]-j<<" ";
    return 0;
}
