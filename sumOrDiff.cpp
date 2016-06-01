#include <bits/stdc++.h>
using namespace std;
bool checkIt(int num, int n,int a[], int t)
{
	int bin[n];//binary array of 2^n-1 length
	//convert num to binary and fill in array
	int i = 0;
	while(i < n)
	{
		bin[i] = num%2;
		num/=2;
		i++;
	}
	//place + if 1 else - if 0 and calculate total sum

	long int sum = 0;
	for (int j = 0; j < n; ++j)
	{
		if(bin[j])
		{
			sum += a[j];
			cout<<"+"<<a[j];
		}
		else
		{
			sum -= a[j];
			cout<<"-"<<a[j];
		}
	}
	cout<<"="<<sum;
	if(sum == t)
		cout<<"<-"<<endl;
	else 
		cout<<endl;
	//if total sum == t rerurn true
	if(sum == t)
		return true;
	else return false;
}
int main()
{
	int n,t;
	cin>>n;
	cin>>t;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int limit = 1<<n;
	int count = 0;
	for (int i = 0; i < limit ; ++i)
	{
		if(checkIt(i,n,a,t))
			count++;
	}
	cout<<count<<endl;
}