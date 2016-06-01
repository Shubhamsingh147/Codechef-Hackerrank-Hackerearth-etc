#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int fibo[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025};
	int t,i,x,count;
	cin>>t;
	while(t--)
	{
		count=0;
		cin>>x;
		while(x!=0)
		{
			for (i = 0; fibo[i] <= x; ++i);
			count++;
			x = x - fibo[i-1];
		}
		cout<<count<<endl;
	}
}