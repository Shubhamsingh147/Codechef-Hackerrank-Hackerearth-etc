#include <iostream>
using namespace std;
int main(){
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int t,d1,m1,y1,d2,m2,y2;
	cin>>t;
	while(t--){
		cin>>d1>>m1>>y1>>d2>>m2>>y2;
		//1/1/1900 was monday
		int years = y2 - y1 + 1;
		int extra_days = 0;
		int rem = 4 - (y1 % 4);
		if ( y1 % 4 != 0) 
				extra_days = extra_days;
			else if ( y1 % 100 != 0){
				if(m1 <= 2 )
					extra_days++;
			}
			else if ( y1 % 400 != 0)
				extra_days = extra_days;
			else
				if(m1 <= 2 )
					extra_days++;

		for (int i = y1 + rem; i < y2; i+=4)
		{
			if ( i % 4 != 0) 
				extra_days = extra_days;
			else if ( i % 100 != 0)
				extra_days++;
			else if ( i % 400 != 0)
				extra_days = extra_days;
			else
				extra_days++;
		}

		if ( y2 % 4 != 0) 
				extra_days = extra_days;
			else if ( y2 % 100 != 0){
				if(m1 > 2 )
					extra_days++;
			}
			else if ( y2 % 400 != 0)
				extra_days = extra_days;
			else
				if(m1 > 2 )
					extra_days++;
		cout<<"extra_days = "<<extra_days<<endl;
		int between_days = (y2 - y1 -  1) * 365 + extra_days;
		cout<<"between_days = "<<between_days<<endl;
		int before_days = 0;
		for (int i = m1 + 1; i <= 12; ++i)
		{
			before_days += months[i-1];
		}
		before_days += months[m1 - 1] - d1 + 1; 
		cout<<"before_days = "<<before_days<<endl;
		int after_days = 0;
		for (int i = 0; i < m2 - 1; ++i)
		{
			after_days += months[i];
		}
		after_days += d2;
		cout<<"after_days = "<<after_days<<endl;
		int final_days = before_days + between_days + after_days;
		cout<<final_days<<endl;
	}
}