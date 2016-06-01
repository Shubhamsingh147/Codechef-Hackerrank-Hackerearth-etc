#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>      /* printf */
#include <stdlib.h> 
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	int c;
	cin>>c;
	long long int count=0;
	long long int logr=log10(n);
	for(long long int i=pow(10,logr)+2; i<pow(10,logr+1); i+=3)
	{
			vector<int> v;
			long long int m=n,j=i;
			while(m)
			{
				v.push_back( abs( m%10 - j%10) );
				m/=10;
				j/=10;
			}
			long long int sum=0;
			for(int l=0;l<v.size();l++)
				sum+=v.at(l);
			if(sum<=c)
			{
				count++;
			}
	}
	cout<<count<<endl;
}