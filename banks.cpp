#include <cmath>
#include <limits.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    bool flag1 = false;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
        if(a[i] < 0)
            flag1 = true;
    }
    if(!flag1)
        cout<<"0"<<endl;
    else{
        bool flag = false;
        long long int count = 0;
        while(!flag){
            flag = true;
            int i;
            int minm = 0;
            for(i = 0 ; i < n ; i++){
                if(a[i] < 0 & a[i] < a[minm]){
                    minm = i;
                    flag = false;
                }
            }
            if(flag)
                break;
            a[(i+1)%n] += a[i];
            if(i >0)
                a[i-1] += a[i];
            else
                a[n-1] +=a[i];
            a[i] *= -1;
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}