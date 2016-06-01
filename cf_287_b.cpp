#include <iostream>
#include <math.h>  
using namespace std;
int main()
{
    double r,x1,x2,y1,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    double d=sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
    if(d==0)
    	cout<<"0";
    else
    if(d<=r)
		cout<<"1";
	else cout<<ceil(d/(2*r));

}