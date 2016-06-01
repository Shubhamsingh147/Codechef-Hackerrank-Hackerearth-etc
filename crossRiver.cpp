#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <map>
using namespace std;
struct rock{
	int x;
	int y;
	int z;
};
long int n,h,dw,dh,maxi;
map< pair<int,int>, bool> graf;
rock r[100001];
int maxPts[100001];
int maxPoints(int index)
{
	int val = 0;
	int maxVal = -999999999;
	bool flag = true;
	for (int i = 0; i < n; ++i)
	{
		if(graf[make_pair(index,i)] == 1)
		{
			flag = false;
			if(maxPts[i] == -999999999){
				int temp = maxPoints(i);
				val = r[index].z + temp;
				maxPts[i] = temp;
			}
			else
				val = r[index].z + maxPts[i];
		}
		if(val > maxVal)
			maxVal = val;
	}
	if(flag == true)
	{
		if(r[index].y + dh >= h){
			maxPts[index] = r[index].z;
			return r[index].z;
		}
		else return -999999999;
	}
	else{
		maxPts[index] = maxVal;
		return maxVal;
	}
}
int main(){

	cin>>n>>h>>dh>>dw;	
	for (int i = 0; i < n; ++i)
		cin>>r[i].y>>r[i].x>>r[i].z;
	maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if( (r[j].y - r[i].y) <= dh && r[j].y > r[i].y && abs(r[i].x - r[j].x) <= dw && i != j)
				graf[ make_pair(i,j)] = 1;
		}
	}
	long int curr = 0, maxm = -999999999;
	for (int i = 0; i < 100000; ++i)
	{
		maxPts[i] = -999999999;
	}
	for(int i = 0 ; i < n; i++){
		if( r[i].y <= dh ){	
			if(maxPts[i] == -999999999)
			  	curr = max(0, max(r[i].z, maxPoints(i)));
			else
				curr = max(0, max(r[i].z, maxPts[i]));
		  	if(curr > maxm)
		  		maxm = curr;
		}
	}
	cout<<maxm<<endl;
}