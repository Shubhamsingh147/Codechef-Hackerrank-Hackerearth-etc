#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    string str;
    cin >> n;
    getline(cin,str);
    while(n--) {
        getline(cin,str);
        int l = str.size();
        int arr[5] = {0},x = 0;
        for(int i=0;i<l;i++) {
            if(str[i] == ':') { arr[x] = (str[i+1] - '0'); x++; }
        }
        cout << (arr[1] + arr[2] + arr[0]+arr[3])/3 << endl;
    }
}
