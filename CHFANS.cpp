#include <iostream>
#include <string.h>
#include <cmath>
#include <stdlib.h>
using namespace std;
int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main(){
	int t,u1,u2;
	cin>>t;
	while(t--){
		cin>>u1>>u2;
		int umin = min(abs(u1), abs(u2));
		if(u1 > 0 && u2 > 0)
			cout<<gcd(u1, u2)<<endl;
		else{
			int x = 
			cout<<gcd(abs(u1), abs(u2)) + max(abs(u1), abs(u2))/min(abs(u1), abs(u2))<<endl;
		}
	}
}