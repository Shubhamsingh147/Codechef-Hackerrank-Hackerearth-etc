#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

bool isCorrect (string ss, int k)
{
	if (ss.length() < k)
		return true;
	else if (ss.length() < 2*k + 1)
		{
			int count_0 = 0, count_1 = 0;
			for (int i = 0; i < ss.length(); ++i)
			{
				if (ss[i] == '0')
					count_0++;
				else
					count_1++;
			}
			if (count_1 <= k && count_0 <= k)
				return true;
			else return false;
		}
	else return false;
}
void printArray(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n ; ++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}	
}
int main()
{
	int t,n,k,q,l,r,window;
	string s;
	scanf("%d",&t);
	
	while (t--)
	{
		scanf("%d%d%d",&n,&k,&q);
		cin>>s;
		//int a[n][n];
		window = 1;
		while (window <= k)
		{
			for (int i = 0; i < (n - window + 1); ++i)
			{
				for (int j = i; j < (i + window) ; ++j)
				{
					a[i][j] = 1;	
				}
			}
			window++;
		}
		while (window < 2*k +1 && window < n)
		{
			int count_0 = 0, count_1 = 0;
			for (int i = 0; i < window; ++i)
			{
				if (s[i] == '0')
					count_0++;
				else
					count_1++;
			}
			if (count_1 <= k && count_0 <= k)
					a[0][window-1] = 1;
				else
					a[0][window-1] = 0;
			for (int i = 1; i < (n - window + 1); ++i)
			{
				if (s[i-1] == '0')
					count_0--;
				else
					count_1--;

				if (s[i+window-1] == '0')
					count_0++;
				else
					count_1++;

				if (count_1 <= k && count_0 <= k)
					a[i][i+window-1] = 1;
				else
					a[i][i+window-1] = 0;
			}
			window++;
		}
		while (window < n)
		{
			for (int i = 0; i < (n - window + 1); ++i)
			{
				for (int j = i; j < (i + window) ; ++j)
				{
					a[i][i+window-1] = 0;	
				}
			}
			window++;
		}
		/*printArray(n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = i; j < n; ++j)
			{
				if (isCorrect( s.substr(i, j - i + 1), k) )
					a[i][j] = 1;
				else
					a[i][j] = 0;
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}*/
		for (int i = 0; i < q; ++i)
		{
			scanf("%d%d",&l,&r);
			int ans=0;
			for (int i = l-1; i <= r-1; ++i)
			{
				for (int j = i; j <= r-1; ++j)
				{
					ans+= a[i][j];
				}
			}
			cout<<ans<<endl;
		}
	}
}
/*
1 1 1 0 0 0 0 0 
  1 1 0 0 0 0 0 
    1 1 1 1 0 0 
      1 1 1 0 0 
		1 1 0 0 
		  1 1 0 
			1 1 
			  1

1 1 1 0 0 0 0 0 
1 1 0 0 0 0 0 
1 1 1 1 0 0 
1 1 1 0 0 
1 1 0 0 
1 1 0 
1 1 
1
*/