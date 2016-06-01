#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long int a[100000];

bool sorted(int n){
    for (int i = 0; i < n-1; ++i)
        if( a[i] > a[i+1])
            return false;
    return true;
}
void swap(int i, int j){
    long int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void reverse(int start, int end){
  int temp;
  while(start < end)
  {
    temp = a[start];   
    a[start] = a[end];
    a[end] = temp;
    start++;
    end--;
  }   
} 
int main() {
    int n;
    int flag = 1;
    cin>>n;    
    for(int i = 0; i < n; i++)cin>>a[i];
    int j = 0, k = 0; 
    while(j < n-1 && a[j] <= a[j+1]) j++;   //3 1 2
    k = j;
    if(j == n-1)    //already sorted
        cout<<"yes";                                              //These two are special cases
else if(j == n-2){ //last element not in position 
        if(n > 2)
        {
            if(a[n-3] <= a[n-1] && a[n-2] >= a[n-1])
            {
                cout<<"yes\nswap "<<n-1<<" "<<n;
            }
        }
        else if(a[0] >  a[1])
            cout<<"yes\nswap 1 2";
    } 
else if(j < n-2 && a[j+1] < a[j+2]){ //0<1 && true
        if(a[j] < a[j+2])   //no
        {
            swap(j,j+1);
            if(sorted(n))
                cout<<"yes\nswap "<<j+1<<" "<<j+2;
        }
        else
        {    j++;//j=0 se j=1
            while( j < n-1 && a[j] <= a[j+1]) j++;   //kab tak increase ho ra
            if(j<n-1) j++; //j = 2
           // cout<<"j = "<<j<<endl;
            swap(k,j);
            if( sorted(n) )
                cout<<"yes\nswap "<<k+1<<" "<<j+1;
            else{
                swap(k,j);
                flag = 0;
            }
        }
    }    

    //ab kya hai ki swap se na ho payega,
    //reverse karke dekh lein
    //j = 0, n = 3;
    //3 1 2
 else if( j < n-2 && a[j+1] > a[j+2])
    {
        int l = j;
        while( j < n-1 && a[j] > a[j+1]) j++;
        ///cout<<"j = "<<j<<endl;
        if(j - l == 2){
            swap(l,j);
            if(sorted(n))
                cout<<"yes\nswap "<<l+1<<" "<<j+1;
            else{
                swap(l,j);
                flag = 0;
            }
        }
        else{
            reverse(l,j);
            if(sorted(n))
                cout<<"yes\nreverse "<<l+1<<" "<<j+1;
            else
                cout<<"no";
        }
    }
    if(!flag)
        cout<<"no";
    return 0;
}
/* 1 5 4 3 6 */