#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long int sumofDigits(long long int x)
{
	long long int sum = 0;
	while(x > 0){
		sum += x%10;
		x /= 10;
	}
	return sum;
}
long long int sumofSquareDigits(long long int x)
{
	long long int sum = 0;
	while(x > 0){
		sum += (x%10)*(x%10);
		x /= 10;
	}
	return sum;
}
long long int gcd ( long long int a, long long int b )
{
  	long long int c;
  	while ( a != 0 ) {
    	c = a;
    	a = b%a;  
    	b = c;
  	}
  	return b;
}
int main(){
	long long int t;
	cin>>t;
	while(t--){
		long long int l,r;
		scanf("%lld %lld",&l,&r);
		long long int count = 0;
		for (long long int i = l; i <= r; ++i)
			if(gcd ( sumofDigits(i) , sumofSquareDigits(i) ) == 1)
				count++;
		cout<<count<<endl;
	}
}