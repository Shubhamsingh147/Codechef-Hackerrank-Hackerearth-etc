#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n];
		long long int p = 1, min = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			if(a[i])
				p *= a[i];
		}
		sort(a,a+n);
		if(a[0] > 0)
		{
			cout<<p<<" "<<a[0]<<endl;
			continue;
		}
		if(a[0] == 0 && a[n-1] == 0)
		{
			cout<<"0 0"<<endl;
			continue;
		}
		else if(a[0] == 0)
			min = 0;
		int x = n;
		for (int i = 0; i < n; ++i)
		{
			if(a[i] >= 0)
			{
				x = i;
				break;
			}
		}
		if(x == n){
			if(n%2 == 0)
				cout<<p<<" "<<p/a[n-1]<<endl;
			else
				cout<<p/a[n-1]<<" "<<p<<endl;
		}
		else
		{
			if(x>0)
				min = p/a[x-1];
			if( x % 2 == 0)
			{
				cout<<p<<" "<<min<<endl;
			}
			else
			{
				cout<<min<<" "<<p<<endl;
			}
		}
	}
}