#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char *s;
int n;
int tree[400020];
void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = (s[start]=='0')? 0 : 1;
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);
        tree[node] = ( tree[2*node+1]*(((end-mid)%2)?2:1) + tree[2*node+2])%3;
    }
}
void update(int node, int start, int end, int idx)
{
    if(start == end)
    {
        s[idx] = s[idx]=='0'?1:1;
        tree[node] = 1;
        return;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node+1, start, mid, idx);
        }
        else
        {
            update(2*node+2, mid+1, end, idx);
        }
        tree[node] = ( tree[2*node+1]*(((end-mid)%2)?2:1) + tree[2*node+2] )%3;
    }
}
int query(int node, int start, int end, int l, int r)
{
    if(r < start || end < l){
    return -1;
    }
    if(l <= start && end <= r){
    return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node+1, start, mid, l, r);
    int p2 = query(2*node+2, mid+1, end, l, r);
    
    if(p1 == -1)
        return p2;
    else if(p2 == -1)
        return p1;
    else
        return ( p1 * (((end-mid)%2)?2:1) + p2)%3;
}
int main()
{
    cin>>n;
    s = new char[n+1];
    scanf("%s",s);
    build(0,0,n-1);
    int q,q_type,l,r;
    cin>>q;
    while(q--){
        cin>>q_type;
        if(q_type == 0){
            cin>>l>>r;
            cout<<query(0,0,n-1,l,r)<<endl;
        }
        else
        {
            cin>>l;
            update(0,0,n-1,l);
        }
    }
}