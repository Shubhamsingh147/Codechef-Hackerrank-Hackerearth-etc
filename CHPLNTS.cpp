#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin>>a[i];
		int min = a[0];
		int minIndex = 0;
		for (int i = 1; i < n; i++)
		{
			if(a[i] < min)
			{
				min = a[i];
				minIndex = i;
			}
		}
		int max1 = a[0];
		for (int i = 1; i < minIndex; ++i)
		{
			if(a[i] > max1)
				max1 = a[i];
		}

		int max2;
		if(minIndex < n-1)
			max2 = a[minIndex + 1];
		else
			max2 = a[minIndex];
		for (int i = minIndex + 2; i < n; ++i)
		{
			if(a[i] > max2)
				max2 = a[i];
		}
		cout<<(max2-min)+(max1-min)<<endl;
	}
}