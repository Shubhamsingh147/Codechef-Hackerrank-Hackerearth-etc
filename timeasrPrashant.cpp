#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const double mod = 1.0/120.0;
void print(int h,int m){
	if(h<10) printf("0");
	printf("%d:",h);
	if(m<10) printf("0");
	printf("%d\n",m);
}
int main() {
	int t;
	double diff;
	scanf("%d",&t);
	while(t--){
		scanf("%lf",&diff);
		int m=0,h=0;
		double val = 0;
		val = fmod(val,360.0);
		bool flag=false;
		if(abs(val - diff) < mod || abs(360.0-val-diff) < mod) flag=true;
		while(!flag && h<6){
			m++;
			if(m == 60) {
				h++;
				m=0;
			}
			val = 330.0*h + 5.5*m ;
			val = fmod(val,360.0);
			if(abs(val - diff) < mod || abs(360.0-val-diff) < mod) flag=true;
		}
		if(!flag) continue;
		print(h,m);
		if((h == 0 || h == 6 ) && m==0) ;
		else {
		if(m==0) h=12-h;
		else { m = 60-m ; h = 11 - h ;}
		print(h,m);}
	}
}