#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a[s.length()];
	int n = s.length();
	for (int i = 0; i < s.length(); ++i)
	{
		a[i] = s[i] - '0';
	}
	int i;
	for (i = n-1; i >= 1; --i)
	{
		if(a[i]>a[i-1])
			break;
	}
	//cout<<a[i]<<endl;
	if(i!=0){
		int ind = i-1;
		int mini = i;
		for (int j = i+1; j < n; ++j)
		{
			if(a[j] > a[ind] && a[j] < a[mini])
				mini = j;
		}
		int temp = a[ind];
		a[ind] = a[mini];
		a[mini] = temp;
		sort(a+i,a+n);
	}
	for (int j = 0; j < s.length(); ++j)
	{
		cout<<a[j];
	}
	cout<<endl;
}