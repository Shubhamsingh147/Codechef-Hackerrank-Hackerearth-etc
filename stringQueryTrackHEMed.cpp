#include <iostream>
#include <string.h>
using namespace std;
	
int main()
{
    int t;
    cin>>t;
    int n;
    string s;
    while(t--){
    	cin>>s;
    	int len = s.length();
    	cin>>n;
    	string qr;
    	while(n--){
    		cin>>qr;
    		int len2 = qr.length();
    		long int count = 0;
    		for( int i = 0; i < len; i++)
    		{
    			int alpha[75] = {0};
    			for( int j = i; j < len; j++)
    			{
    				alpha[s[j]-'0']++;
    				bool present = true;
    				for( int k = 0; k < len2; k++)
    					if(!alpha[qr[k] - '0'])
    					{
    						present = false;
    						break;
    					}
    				if(present)
    				count++;
    			}
    		}
    		cout<<count<<endl;
    	}
    }
    return 0;
}
