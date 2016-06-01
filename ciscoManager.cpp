#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
float a[1000];
float fun(float p , int k, int nk, int i){
    if(k == 0 && nk == 0)
        return p;
    if(k == 0 && nk != 0)
        return fun( p*(1-a[i]), k, nk-1, i+1);
    if(nk == 0 && k != 0)
        return fun(p*a[i], k-1, nk, i+1);
    else
        return fun(p*a[i], k-1, nk, i+1) + fun( p*(1-a[i]), k, nk-1, i+1);        
}
int main(){
    int t,k;
    cin>>t;
    int cases = t;
    while(t--){
        cin>>n>>k;
        for(int  i = 0; i < n; i++)
            cin>>a[i];
        printf("Case %d: %.2f\n",cases-t, fun(1,k,n-k,0));      
    }
    return 0;
}