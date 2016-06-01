#include <iostream>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;
struct order{
	long long int id,rcv,num,dead,loss; 
};
bool compr( order a, order b ){
	return (a.rcv < b.rcv);
}
int main()
{
	long long int t,r,g,b,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		order o[n]; 
		
		long long int mintm = INT_MAX;
		long long int maxtm = INT_MIN;
		long long int tot = 0;
		for(long long int i = 0 ; i < n ; i++)
		{
			cin>>o[i].id>>o[i].rcv>>o[i].num>>o[i].dead>>o[i].loss;
			if(mintm > o[i].rcv)
				mintm = o[i].rcv;
			if(maxtm < o[i].dead)
				maxtm = o[i].dead;
			tot += o[i].loss * o[i].num;
		}
		//sort(o,o+n,compr);
		long long int sol = 0;
		for (long long int i = mintm; i < maxtm; ++i)
		{
			long long int max = 0;
			long long int maxInd = 0;
			for(long long int j = 0; j < n ; j++)
			{
				if(o[j].num > 0 && o[j].rcv <= i && o[j].dead > i)
					if(max < o[j].loss)
					{
						max = o[j].loss;
						maxInd = j;
					}
					if(max == o[j].loss)
					{
						if(o[j].dead > o[maxInd].dead)
						{
							max = o[j].loss;
							maxInd = j;
						}
					}
			}
			sol += o[maxInd].loss;
			o[maxInd].num--;
		}
		cout<<tot-sol<<endl;
	}
}		