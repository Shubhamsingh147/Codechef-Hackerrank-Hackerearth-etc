#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,q,u,v;
	cin>>n>>q;
	int a[n+1];
	for (int i = 1; i <= n; ++i)
		cin>>a[i];
	vector<int> sets[n+1];
	map<int ,int> > m;
	for (int i = 1; i <= n; ++i)
	{
		sets[i].push_back(i);
		map[i] = i;
	}
	while(q--){
		cin>>u>>v;
		sets[u].add(sets[v]);
		sets[v] = NULL;
		map[u]+=map[v];
		map[v] = -1;
	}
}
//ab na ho payega, competition ke liye 10 min bacha hai :P