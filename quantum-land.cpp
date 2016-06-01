#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, cur;
    cin>>n;
    vector < pair <int, double> > v(n);
    for (i = 0; i < n; i++) {
        cin>>v[i].first;
        v[i].first--;
        cin>>v[i].second;
        v[i].second /= 100.0;
    }
    int mrk[n], strt[n];
    memset(mrk, 0, sizeof(mrk));
    memset(strt, 0, sizeof(strt));
    vector <int> p;
    int j;
    for (i = 0, j = 1; i < n; i++) {
        if (!mrk[i]) {
            cur = i;
            while (!mrk[cur]) {
                mrk[cur] = 1;
                strt[cur] = j;
                cur = v[cur].first;
            }
            if (strt[cur] == j)
                p.push_back(cur);
            j++;
        }
    }
    double ans = 0.0, tmp;
    for (i = 0; i < p.size(); i++) {
        cur = p[i];
        tmp = 1.0;
        do {
            tmp *= v[cur].second;
            cur = v[cur].first;
        } while (cur != p[i]);
        ans += tmp;
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}