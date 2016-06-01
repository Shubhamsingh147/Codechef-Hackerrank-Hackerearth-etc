#include <iostream>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string x,y;
		int a,b,c;
		cin>>x>>y;
		cin>>a>>b>>c;
		int x_len = x.length();
		int y_len = y.length();
		int ar[26] = {0};
		int br[26] = {0};
		if(x_len == y_len)
		{
			int charsMatch = 0;
			for (int i = 0; i < x_len; ++i)
				ar[x[i] - 'a']++;
			for (int i = 0; i < y_len; ++i)
				br[y[i] - 'a']++;
			for(int i = 0; i < 26; ++i)
				charsMatch += abs(ar[i] - br[i]);
			charsMatch /= 2;
		//	cout<<charsMatch<<endl;
			if( a+b < c )
				cout<< (charsMatch) * (a+b) <<endl;
			else
				cout<< (charsMatch) * c <<endl;
		}
		else if(x_len < y_len)
		{
			int diffChars = 0;
			for (int i = 0; i < x_len; ++i)
				ar[x[i] - 'a']++;
			for (int i = 0; i < y_len; ++i)
				br[y[i] - 'a']++;
			for(int i = 0; i < 26; ++i)
				if(ar[i] < br[i])
					diffChars += br[i] - ar[i];
			int commChars = y_len - diffChars;

			cout<< (y_len-x_len)*b + min( (x_len - commChars)*(a+b),  (x_len - commChars)*c ) <<endl;

		}
		else
		{
			int diffChars = 0;
			for (int i = 0; i < x_len; ++i)
				ar[x[i] - 'a']++;
			for (int i = 0; i < y_len; ++i)
				br[y[i] - 'a']++;
			for(int i = 0; i < 26; ++i)
				if(ar[i] < br[i])
					diffChars += br[i] - ar[i];
			int commChars = y_len - diffChars;
			cout<< (x_len - y_len)*a + min( (diffChars)*(a+b) , (diffChars)*c ) <<endl;
		}
	}
}
