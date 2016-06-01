#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
void multiply(int a[], int n) {
    int carry = 0,carry2 = 0;
    
    for(int i = 159; i > 0; i--)
    {
        carry2 = ((a[i] * n) + carry)/10;
        a[i] =  ((a[i] * n) + carry)%10;
        carry = carry2;
    }
}

int main() {
    int n;
    cin>>n;
    int a[160] = {0};
    a[159] = 1;
    for (int i = 2; i <= n; i++) {
        multiply(a,i);
    }
    int j = 0;
    while(a[j] == 0)j++;
    for (int i = j; i < 160; ++i)
        cout<<a[i];
    cout<<endl;
    return 0;
}
