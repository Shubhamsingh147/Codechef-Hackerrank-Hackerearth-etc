#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
long int n,min_diff;
long int arr[100];
long int min(long int a, long int b){
    return a>b?b:a;
}
long int binSearch( long int start, long int x,long int end = n-1){
    
    long int mid = (n-1)/2;
    while(arr[mid] != x && start < end)
    {
        if(arr[mid] > x)
            end = mid -1;
        else
            start = mid+1;
        
        mid = (start + end)/2;
    }
    cout<<arr[mid+1]-x<<endl;
    min_diff = min ( abs(mid-1>=0? arr[mid-1]-x : INT_MAX) , min( abs(arr[mid]-x), abs(mid+1<=n-1? arr[mid+1]-x : INT_MAX) ));
    if(mid-1 >=0 && abs(arr[mid-1]-x) == min)
        mid--;
    else if(mid+1 >=0 && abs(arr[mid+1]-x) == min)
        mid++;
    cout<<"mid"<<mid<<endl;
    return mid;
}

int main(){
    long int p,q,ans,res;
    cin>>n;
    for(long int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cin>>p>>q;
    if(q <= arr[0])
        cout<<p;
    else if(p >= arr[n-1])
        cout<<q;
    else if(p <= arr[0] && q >=arr[n-1]){
        res = abs(arr[0]-p);
        for (int i = 0; i < n-1; ++i)
        {
            if( abs(arr[i] - arr[i+1])/2 > res )
                res = abs(arr[i] - arr[i+1])/2;
        }
        if(q - arr[n-1] > res)
            res = q - arr[n-1];
        cout<<res;
    }
    else if(p > arr[0] && q < arr[n-1]){
        long int p_index = binSearch(0,p);
        res = arr[p_index - 1] - p;
        for (int i = 0; i < n-1; ++i)
        {
            if( arr[i])
        }
    }
    return 0;
}