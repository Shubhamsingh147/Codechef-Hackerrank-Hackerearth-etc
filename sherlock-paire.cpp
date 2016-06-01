#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int nums[1000001];
int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        long long int ans = 0;
        long int a[n];
        for(int i = 0 ; i < 1000001 ; i++) nums[i] = 0;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>a[i];
            nums[a[i]]++;
        }
        for (int i = 0; i < 1000001; ++i)
        {
            long long int num = nums[i];
            if(num > 1)
                ans += num*(num-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
