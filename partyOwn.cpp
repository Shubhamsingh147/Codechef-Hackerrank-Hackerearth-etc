#include <iostream>
using namespace std;
int main(){
	int w,n;
	cin>>w>>n;
	while(w&&n){
		int c[n+1],val[n+1];
		for (int i = 1; i <= n; ++i)
		{
			cin>>c[i]>>val[i];
		}
		int k[w+2][n+2];

		for (int i = 0; i <= n; ++i)
		{
			k[0][i] = 0;
		}
		for (int i = 0; i <= w; ++i)
		{
			k[i][0] = 0;
		}

		for (int i = 1; i <= w; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if(i >= c[j])
					k[i][j] = max( k[i][j-1], (k[ i-c[j] ][j-1] + val[j]));
				else
					k[i][j] = k[i][j-1];
			}
		}
		int maxm = k[0][n];
		int maxIndex = 0;
		for (int i = 1; i <= w; ++i)
		{
			if( maxm < k[i][n] )
			{
				maxm = k[i][n];
				maxIndex = i;
			}
		}
		cout<<maxIndex<<" "<<maxm<<endl;
		cin>>w>>n;
	}
}