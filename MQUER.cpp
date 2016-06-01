#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100005];
struct seg
{	int max;
	int min;
}tree[500005];
void build(int node,int a,int b) //O(2*n)
{	if(a>b)
		return ;
	if(a==b)
	{	tree[node].max=arr[a];
		tree[node].min=arr[a];
		return ;
	}	
	build(2*node,a,(a+b)/2);
	build(2*node+1,(a+b)/2+1,b);
	tree[node].max=max(tree[2*node].max,tree[2*node+1].max);
	tree[node].min=min(tree[2*node].min,tree[2*node+1].min);
	return;
}
struct seg query(int node,int a,int b,int start,int end)	//O(log n)
{	struct seg left;
	struct seg right;
	if(a>b||b<start||a>end)
		return ((seg){0,1000000005});
	if(start<=a&&b<=end)
		return tree[node];
	left=query(2*node,a,(a+b)/2,start,end); 
	right=query(2*node+1,(a+b)/2+1,b,start,end) ;
	return (seg){ max(left.max,right.max) ,min(left.min,right.min) } ;
}
int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
int main()
{	int N,Q,p,q,i;
	struct seg ans;
	char ch;
	scanf("%d%d",&N,&Q);
	for(i=0;i<N;i++)
		scanf("%d",&arr[i]);
	build(1,0,N-1);	
	for (int i = 0; i < 2*N; ++i)
	{
		cout<<tree[i].max<<" ";
	}
	cout<<endl;
	for (int i = 0; i < 2*N; ++i)
	{
		cout<<tree[i].min<<" ";
	}
	cout<<endl;	
	for (int i = 0; i < Q; ++i)
	{
		cin>>p>>q;
		ans = query(1,0,N-1,p-1,q-1);
		cout<<"ans-max"<<ans.max<<endl<<"ans-min"<<ans.min<<endl;	
	}return 0;
}