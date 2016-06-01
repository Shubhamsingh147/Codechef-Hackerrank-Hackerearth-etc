#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
int ar[1000002];
int trie[2000006];
void build(int node,int a,int b) //O(2*n)
{	if(a>b)
		return ;
	if(a==b)
	{	
		trie[node]=ar[a];
		return ;
	}	
	build(2*node,a,(a+b)/2);
	build(2*node+1,(a+b)/2+1,b);
	trie[node]=max(trie[2*node],trie[2*node+1]);
	return ;
}
int query(int node,int a,int b,int start,int end)
{	int left,right;
	if(a>b||b<start||a>end)
		return 0;
	if(start<=a&&b<=end)
		return trie[node];
	left=query(2*node,a,(a+b)/2,start,end);
	right=query(2*node+1,(a+b)/2+1,b,start,end) ;
	return max(left,right);
}
int main(){
	int n, m;
	char sign,name;
	cin>>n>>m;
	map<int,int> mp;
	long int k;
	for (int i = 0; i < n; ++i)
		scanf("%d",&ar[i]);
	build(1,0,n-1);
	long int highest = query(1,0,n-1,0,n-1);
	int ans;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
 			mp[query(1,0,n-1,i,j)]++;
 	// cout<<endl;
 	// 	for (std::map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it)
 	// 		cout<<it->first<<" "<<it->second<<" ";
 	// 	cout<<endl;

	for (int i = 0; i < m; ++i)
	{
		long int count = 0;
	 	cin>>sign>>k>>name;
	 	if (sign == '>')
	 	{
	 		for (map<int,int>::iterator it=mp.end(); it!=mp.begin(); --it)
	 			if(it->first > k)
		 			count+=it->second;
		 		else
		 			break;
	 	}
	 	else if (sign == '<')
	 	{
	 		for (map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it)
	 			if(it->first < k)
		 			count+=it->second;
		 		else
		 			break;
	 	}
	 	else count = mp[k];
		
		if(count%2 == 0)
			name = (name == 'D')? 'C' : 'D';
		cout<<name;
	}
}