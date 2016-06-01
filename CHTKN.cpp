#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
int main(){
	int fibo[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040};
	int t,n;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>s;
		cout<<fibo[n+1]<<endl;
		for (int i = 0; i < n;)
		{
			if(s[i] > s[i+1] && i+1 < n){
				char temp = s[i];
				s[i] = s[i+1];
				s[i+1] = temp;
				i+=2;
			}
			else
				i+=1;
		}
		cout<<s<<endl;
	}
}