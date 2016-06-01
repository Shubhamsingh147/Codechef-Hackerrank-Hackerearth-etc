#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int checkedTuple[5000002];
pair<long long int,long long int> CheckTuple(long long int n)
{
    long long int k = sqrt(n/2.0);
    for (long long int i = 1; i <= k; i++) {
        long long int tmp = sqrt((double)(n - i * i));
        if ((tmp * tmp) == (n - i * i)) {
            return make_pair(tmp*tmp-i*i, 2*tmp*i);
        }
    }
    return make_pair(0,0);
}
int main()
{
    int sqr = sqrt(5000001);
    for (int i = 1; i <= 5000001; ++i)
        checkedTuple[i] = -1;
    int t,n;
    scanf("%d",&t);
    for (int i = 5; i <= 10000; ++i)
    {
        if(checkedTuple[i] == -1)
        {
            int mul = 1000001/i;
            pair<long long int,long long int> res = CheckTuple(i*i);
            if( res.first!=0 && (i < res.first + res.second) )
            {
                for (int j = 1; j < mul; ++j)
                {
                    checkedTuple[j*i] = 1;
                }
            }
            else
                checkedTuple[i] = 0;
        }
        if(checkedTuple[i] == 1)
            cout<<i<<" ";
    }
    // while(t--)
    // {
    //     scanf("%d",&n);
    //     if(checkedTuple[n] != -1){
    //         if(checkedTuple[n] == 1)
    //             cout<< "YES\n";
    //         else
    //             cout<< "NO\n";
    //         continue;
    //     }
    //     else
    //     { 
    //         pair<long long int,long long int> res = CheckTuple(n*n);
    //         if( res.first!=0 && (n < res.first + res.second) )
    //         {
    //             printf("YES\n");
    //         }
    //         else
    //         {
    //             printf("NO\n");
    //         }
    //     }
    // }
}