#include <iostream>
#include <map>
using namespace std;
int main(){
	int t;
	long int n;
	cin>>t;
	while(t--){
		cin>>n;
		map<int,int> mymap;
		for (long int i = 1; i < 100000; ++i)
		{
			if( !mymap[ (i^(i+1)) ] )
				mymap[(i^(i+1))] = i;
		}
		for (map<int,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		{
			cout<<it->first<<" "<<it->second<<endl;
		}
	}
}