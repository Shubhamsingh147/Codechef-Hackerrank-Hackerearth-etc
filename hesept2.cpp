#include <iostream>
#include <map>
using namespace std;
long long a,b;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long count = 0;
		long long quo = 0;
		cin>>a>>b;
		while(a != 1 && b != 1){
			if(a > b){
				quo = a/b;
				a = a % b;
			}
			else{
				quo = b/a;
				b = b % a;
			}
			count+= quo;
		}
		if(a == 1)
			cout<<count + b - 1<<endl;
		else
			cout<<count + a -1<<endl;
	}
}