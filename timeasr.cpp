#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <stdlib.h>
using namespace std;
double min(double x, double y) { return (x < y)? x: y; }
int main(){
	int t,temp_i,temp_j;
	cin>>t;
	double angle;
	string zero = "0", colon = ":";
	int i,j,k=0;
	while(t--){
		cin>>angle;
		if(angle < 0+(1.0/120.0))
			cout<<"00:00"<<endl;
		else if(angle > 180-(1.0/120.0))
			cout<<"06:00"<<endl;
		else
		{
			double calc;
			bool flag  = 0;
			for (i = 0; i < 6; ++i)
			{
				for (j = 0; j < 60; ++j)
				{
					calc = (660.0*i + 11.0*j)/2.0;
					calc = fmod(calc, 360.0);
					if(abs(calc-angle) < (1.0/120.0) || abs(360.0-calc-angle) < (1.0/120.0) )
					{
						flag = 1;
						char si[2], sj[2];
						sprintf(si,"%d",i);
						sprintf(sj,"%d",j);
						if(i < 10 && j < 10)
							cout<<zero+si+colon+zero+sj;
						else if( i < 10)
							cout<<zero+si+colon+sj;
						else if( j < 10)
							cout<<si+colon+zero+sj;
						else
							cout<<si+colon+sj;
						
						cout<<endl;
						temp_i = i, temp_j = j;
						if(j == 0)
						{
							sprintf(si,"%d",12-i);
							sprintf(sj,"%d",j);
							if(12-i < 10 && j < 10)
								cout<<zero+si+colon+zero+sj;
							else if( 12-i < 10)
								cout<<zero+si+colon+sj;
							else if( j < 10)
								cout<<si+colon+zero+sj;
							else
								cout<<si+colon+sj;
							cout<<endl;
						}
						else
						{
							sprintf(si,"%d",11-i);
							sprintf(sj,"%d",60-j);
							if(11-i < 10 && 60-j < 10)
								cout<<zero+si+colon+zero+sj;
							else if( 11-i < 10)
								cout<<zero+si+colon+sj;
							else if( 60-j < 10)
								cout<<si+colon+zero+sj;
							else
								cout<<si+colon+sj;
							cout<<endl;
						}
						i = temp_i;
						j = temp_j;
						break;
					}
				}
				if(flag)
					break;
			}
		}
	}
}