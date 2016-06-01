#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int BS(int n,int elem){
	int low = 1;
	int high = n;
	while(1){
		int k = low + (high-low)/2; //k is mid here
        int g1 = n%k ;
        int g2 = k - g1 ;
        int sz1 = n/k + 1 ;
        int sz2 = n/k ;
        int ret = g1*sz1*g2*sz2 + g1*(g1-1)*sz1*sz1/2 + g2*(g2-1)*sz2*sz2/2 ;
		if(ret == elem || low > high)
		return k;
		if(ret<elem)
		low = k + 1;
		else high = k-1;	
	}
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<BS(n,m)<<endl;
    }
    return 0;
}
