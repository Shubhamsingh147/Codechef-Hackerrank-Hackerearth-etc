#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	string a,b;
	while(t--){
		cin>>a>>b;
		sort( b.begin(), b.end() );
		int j = 0;
		for (int i = 0; i < a.length() && j < b.length(); ++i)
		{
			if( a[i] > b[j] )
			{
				a[i] = b[j++];
			}
		}
		cout<<a<<endl;
	}
}