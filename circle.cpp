#include <iostream>
#include <math.h>  
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main()
{
    int t,n;
    double x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
    	cin>>n>>x1>>y1>>x2>>y2;
    	double pk[n],pj[n];
        double min_pk=100000,min_pj=100000;
    	for(int i=0;i<n;i++)
    	{
    		cin>>pk[i];
    		if(pk[i]<min_pk)
    			min_pk=pk[i];
    	}
    	for(int i=0;i<n;i++)
    	{
    		cin>>pj[i];
    		if(pj[i]<min_pj)
    			min_pj=pj[i];
    	}
    	double d= sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
        double r=min_pk,R=min_pj;
        if(R < r)
        {
           r = min_pj;
           R = min_pk;
        }
        double part1 = r*r*cos((d*d + r*r - R*R)/(2*d*r));
        double part2 = R*R*cos((d*d + R*R - r*r)/(2*d*R));
        cout<<"\nexp="<<abs((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R))<<endl;
        double part3 = 0.5*sqrt(abs((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R)));
        cout<<endl<<"d="<<d<<" p1="<<part1<<" p2="<<part2<<" p3="<<part3<<endl;
        double intersectionArea = part1 + part2 - part3;
    	cout<<intersectionArea<<endl;
    }
    return 0;
}
