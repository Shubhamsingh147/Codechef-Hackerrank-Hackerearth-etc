#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int a[]){
    int i = 0;
    while( i <= 9999 && !a[i] ) i++;
    if(i == 10000)
        cout<<"0";
    else
        for (int j = i; j < 10000; ++j) cout<<a[j];
    cout<<endl;
}
int* add(int *ans, int a[], int shift){
    int carry = 0, carry2 = 0;
    for (int i = 9999-shift; i >=0; i--)
    {
        carry2 = ( ans[i] + carry + a[i+shift] ) / 10;
        ans[i] = ( ans[i] + a[i+shift] + carry) % 10;
        carry = carry2;
    }
    return ans;
}
int* multiplySingle(int a[], int n) {
    int carry = 0,carry2 = 0;
    int *res = new int[10000];
    for(int i = 9999; i >= 0; i--)
    {
        carry2 = ((a[i] * n) + carry)/10;
        res[i] =  ((a[i] * n) + carry)%10;
        carry = carry2;
    }
    return res;
}
int* multiply(int a[], int b[]){
    int *store[10];
    
    int *res = new int[10000];
    
    for (int i = 0; i < 10; ++i) store[i] = new int[10000];
    
    for (int i = 0; i < 10000; ++i) store[0][i] = 0;
    
    store[1] = a;    
    
    for (int i = 2; i < 10; ++i) store[i] = multiplySingle(a,i);
    for (int i = 0; i < 10000; ++i) res[i] = 0;
    for (int i = 9999; i >= 0; i--) res = add(res, store[b[i]], 10000-i-1);      
    
    return res;
}
int* calc(int a[], int b[]){
   	int *arr = new int[10000];
    arr = multiply(a,a);
    arr = add(arr,b,0);
    return arr;
}
int main() {
    int a,b,n;
    cin>>a>>b>>n;
    int* dp[n];
    for (int i = 0; i < n; ++i)
    	dp[i] = new int[10000];
    for (int i = 0; i < 10000; ++i)
    {
        dp[1][i] = 0;
        dp[2][i] = 0;
    }
    
    dp[1][9999] = a;
    dp[2][9999] = b;    

    for(int i = 3; i <= n; i++)
    	dp[i] = calc(dp[i-1], dp[i-2]);
    printArray(dp[n]);
    return 0;
}
