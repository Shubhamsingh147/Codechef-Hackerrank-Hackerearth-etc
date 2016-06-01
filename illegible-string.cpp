#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int maxlen = 0;
	for (int i = 0; i < n; ++i)
	{
		if(s[i] == 'w')
			maxlen++;
	}
	int minlen = 0;
	for (int i = 0; i < n; ++i)
	{
		if(s[i]!='v' && s[i]!='w')
			minlen++;
		int v = 0, w = 0;
		int flag = false;
		while(s[i] == 'v' || s[i] == 'w'){
			if(s[i] == 'v') 
				v++;
			else 
				w++;
			i++;
			flag = true;
		}
		if(flag)
			i--;
		minlen += (v%2) + w + (v/2);
	}
	cout << minlen << " " << n + maxlen;
}