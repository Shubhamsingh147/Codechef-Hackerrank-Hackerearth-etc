#include <iostream>
using namespace std;

int a[1000][1000];
int m,n,count;

int getCount(int x1, int y1, int x2, int y2)
{
	if (x1 == x2 && y1 == y2)
		count ++;
	else
	{
		if (x1 < m - 1 && a[x1][y1] > a[x1+1][y1])
			getCount(x1+1,y1,x2,y2);

		if (y1 < n - 1 && a[x1][y1] > a[x1][y1+1])
			getCount(x1,y1+1,x2,y2);

		if (x1 > 0 && a[x1][y1] > a[x1-1][y1])
			getCount(x1-1,y1,x2,y2);

		if (y1 > 0 && a[x1][y1] > a[x1][y1-1])
			getCount(x1,y1-1,x2,y2);
	}
}

int main()
{
	cin>>m>>n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin>>a[i][j];
	int x1,y1,x2,y2;
	while(1)
	{
		cout<<"Enter Source x and y: ";
		cin>>x1>>y1;
		cout<<"\nEnter Destination x and y: ";
		cin>>x2>>y2;
		count = 0;
		getCount(x1,y1,x2,y2);
		cout<<"\nNo. of ways from S to D are: "<<count<<endl;
	}
}