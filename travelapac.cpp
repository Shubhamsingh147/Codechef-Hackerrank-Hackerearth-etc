#include <iostream>
#include <map>
#include <vector>
#include <limits.h>
using namespace std;
int n;
int findMin(int dist[]){
	int min = INT_MAX;
	int minIndex = 1;
	for (int i = 1; i <= n; ++i)
	{
		if ( dist[i] < min )
		{
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int main(){
	int t,cases;
	cin>>t;
	cases = t;
	while(t--){
		int m,x,y,z,s,k,start,d;
		pair<int,int> pr,pr2;
		cin>>n>>m>>k;
		int a[n+1][n+1];
		map<pair<int,int> , vector<vector<int> > > mp;
		int dist[n+1];
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				a[i][j] = 0;
			
		for (int i = 0; i < m; ++i)
		{
			cin>>x>>y;
			a[x][y] = 1;
			a[y][x] = 1;
			pr = make_pair(x,y);
			pr2 = make_pair(y,x);
			int ghj;
			vector<int> times;
			for(int j = 0 ; j < 24; j++)
			{
				cin>>ghj;
				times.push_back(ghj);
			}
				mp[pr].push_back(times);
				mp[pr2].push_back(times);
		}
		cout<<"Case #"<<cases-t<<": ";
		for (int i = 0; i < k; ++i)
		{
			cin>>d>>start;
			s = 1;
			for (int i = 1; i <= n; ++i)
			{
				dist[i] = INT_MAX;
			}
			dist[s] = 0;
			int temp,i=0;
			while(dist[d]!=temp){
				if(dist[d]!=INT_MAX)
					temp = dist[d];
				int index = findMin(dist);
				int timeHere = (i++ + start)%24;
				for (int j = 1; j <= n; ++j)
				{
					if (a[index][j] && (dist[index] != INT_MAX))
					{
						vector<vector<int> > vc = mp[make_pair(index,j)];
						int mini = INT_MAX;
						for (int r = 0; r < vc.size() ; ++r)
						{
							if(mini > vc[r][timeHere])
								mini = vc[r][timeHere];
						}
						if (dist[j] > (dist[index] + mini))
							dist[j] = dist[index] + mini;
				
					}
				}
			}
			if(dist[d]!=INT_MAX)
				cout<<dist[d]<<" ";
			else
				cout<<-1<<" ";
		}
		cout<<endl;
	}
}