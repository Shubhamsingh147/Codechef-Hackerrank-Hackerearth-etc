#include <iostream>
using namespace std;
long long int min(long long int a, long long int b) { return a>b?b:a; }
int main() {
		int n,s;
		cin>>n>>s;
		long long int dol[n+1],cen[n+1];
		int max = -1;
		for(int i = 0; i < n; i++)
		{
			cin>>dol[i];
			cin>>cen[i];
			if(dol[i] <= s && cen[i] == 0)
				if( 0 > max)
					max = 0;
			if(dol[i] < s && cen[i] != 0)
			{
				if(100-cen[i] > max)
					max = 100-cen[i];
			}
		}
		cout<<max<<endl;
}