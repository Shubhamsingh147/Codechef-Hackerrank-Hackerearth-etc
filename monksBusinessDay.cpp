#include <iostream>
#include <limits.h>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int n;

int main(){
	int t;
	cin>>t;
	while(t--){
		int m,x,y,c,s=1;
		cin>>n>>m;
		if(n == 1){
			cout<<"0"<<endl;
			continue;
		}
		map<pair<int,int>,int> a;
		bool included[n+1];
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d %d",&x,&y,&c);
			a[make_pair(x,y)] = c;
		}
		for (int i = 1; i <= n; ++i)
			included[i] = false;
		bool flag = false;
		queue<pair<int,int>> q;
		q.push(make_pair(s,0));
		included[s] = 1;
		while(!q.empty())
		{
			int ind = q.front().first;
			int count = q.front().second;
			q.pop();
			for(vector<int>::iterator i = a[ind].begin(); i != a[ind].end(); ++i)
			{				
				int j = *i;
				if(!included[j] )
				{	
					included[j] = 1;
					if(j == n)
					{
						cout<<count+1<<endl;
						flag = true;
						break;
					}
					else
						q.push(make_pair(j,count+1));
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
	}
}