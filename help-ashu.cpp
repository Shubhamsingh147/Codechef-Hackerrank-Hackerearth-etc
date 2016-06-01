#include <iostream>
#define ll long long
using namespace std;
ll A[100010];
int tree[400020];
void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = (A[start]%2) ? 1:0;
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        A[idx] = val;
        tree[node] = A[idx]&1;
    }
    else
    {
        ll mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
ll query(int node, int start, int end, int l, int r)
{
    if(r < start || end < l){
    return 0;
    }
    if(l <= start && end <= r){
    return tree[node];
    }
    int mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}
int main(){
int n;
cin>>n;
for(ll i=1;i<=n;i++) scanf("%lld",&A[i]);
build(1,1,n);
ll q;
cin>>q;
while(q--){
int a,b;int c;
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
if(a==0){
update(1,1,n,b,c);
}
else if(a==1){
cout<<(c-b+1-query(1,1,n,b,c))<<endl;
}
else cout<<query(1,1,n,b,c)<<endl;
}
}