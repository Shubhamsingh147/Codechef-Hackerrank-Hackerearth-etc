#include <iostream>
#include <cmath>

using namespace std;
int a[1024][1024];
int val;
void makeMatrix(int x, int y, int k)
{
	if(k==1)
	{
		a[x][y] = val++;
		return;
	}
	makeMatrix( x, y, k/2);
	makeMatrix( x, y+k/2, k/2);
	makeMatrix( x+k/2, y, k/2);
	makeMatrix( x+k/2, y+k/2, k/2);
}
int main()
{
	int n;
	cin>>n;
	int pow = 1<<n;
	val = 1;
	makeMatrix( 0, 0, pow);
	for (int i = 0; i < pow; ++i)
	{
		for (int j = 0; j < pow; ++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}