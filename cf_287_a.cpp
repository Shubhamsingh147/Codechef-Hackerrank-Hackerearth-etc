#include <vector>
#include <iostream>
#include <math.h>  
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
using namespace std;
bool pairCompare(const pair<int,int>& firstElem, const pair<int,int>& secondElem) {
  return firstElem.first < secondElem.first;

}
int main()
{
    int n,k;
    vector< pair<int,int> > a;
    cin>>n>>k;
    int x;
    for(int i=0;i<n;i++)
    {
    	cin>>x;
    	a.push_back(make_pair(x,i));
    }
    sort(a.begin(), a.end(), pairCompare);
    int sum=0,i=0;
    while(sum<=k && i<n)
    {
    	sum+=a.at(i).first;
    	i++;
    }
    if(sum>k)
    	sum-=a.at(--i).first;
    cout<<i<<endl;
    for(int j=0;j<i ;j++)
    	cout<<a.at(j).second + 1<<" ";
}
