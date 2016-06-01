#include <iostream>
using namespace std;

int dow(int d, int m, int y)
{
   static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
   y -= m < 3;
   return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

int main(){
	int t,d1,m1,y1,d2,m2,y2;
	cin>>t;
	while(t--){
		int count = 0;
		cin>>d1>>m1>>y1>>d2>>m2>>y2;
		if(d1 <= 13){
			if(dow(13,m1,y1) == 5)
				count++;
		}
		if( y2 - y1 > 0 ){
			for (int i = m1 + 1; i <= 12; ++i)
			{
				if(dow(13,i,y1) == 5)
					count++;
			}
			for (int i = y1 + 1; i < y2; ++i)
			{
				for (int j = 1; j <= 12; ++j)
				{
					if(dow(13, j, i) == 5)
						count ++;
				}
			}
			for (int i = 1; i < m2; ++i)
			{
				if (dow(13,i,y2) == 5)
					count++;
			}
			if(d2 >= 13){
				if(dow(13,m2,y2) == 5)
					count++;
			}
		}
		else{
			//cout<<"coming here:";
			for (int i = m1 + 1; i < m2 ; ++i)
			{
				if(dow(13,i,y1) == 5)
					count++;
			}
			if(d2 >= 13 && m2 != m1)
				if(dow(13,m2,y2) == 5)
					count++;
		}
		cout<<count<<endl;
	}
}
