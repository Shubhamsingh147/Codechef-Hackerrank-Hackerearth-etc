#include <iostream>
using namespace std;
int main(){
	int n, x, sum = 0, i = 1, j = 1, k = 1;
	int twoFirstMin = 1001;
	int twoSecondMin = 1001;
	int oneFirstMin = 1001;
	int oneSecondMin = 1001;

	int twoFirstMinIndex = 0;
	int twoSecondMinIndex = 0;
	int oneFirstMinIndex = 0;
	int oneSecondMinIndex = 0;
	cin>>n;
	int zero[n+1];
	int one[n+1];
	int two[n+1];
	while(n--){
		cin>>x;
		if(x % 3 == 0){
			zero[i++] = x;
			sum += x;
		}
		else if(x % 3 == 2){
			two[j++] = x;
			sum += x;
			if(twoFirstMin > x){
				twoFirstMin = x;
				twoFirstMinIndex = j-1;
			}
		}
		else
		{
			one[k++] = x;
			sum += x;
			if(oneFirstMin > x){
				oneFirstMin = x;
				oneFirstMinIndex = k-1;
			}
		}
	}
	for (int q = 1; q < j; ++q)
	{
		if(twoSecondMin > two[q] && q!=twoFirstMinIndex)
		{
			twoSecondMin = two[q];
			twoSecondMinIndex = q;
		}
	}

	for (int q = 1; q < k; ++q)
	{
		if(oneSecondMin > one[q] && q!=oneFirstMinIndex)
		{
			oneSecondMin = one[q];
			oneSecondMinIndex = q;
		}
	}
	// cout<<"11 "<<oneFirstMin<<endl;
	// cout<<"12 "<<oneSecondMin<<endl;
	// cout<<"21 "<<twoFirstMin<<endl;
	// cout<<"22 "<<twoSecondMin<<endl;
	int twos = (j-1) % 3;
	//cout<<"twos"<<twos<<endl;
	int ones = (k-1) % 3;
	//cout<<"ones"<<ones<<endl;
	if(twos == ones)
		cout<<sum<<endl;
	else{
		if(twos == 2 && ones == 1)
			cout<<sum - min( two[twoFirstMinIndex] , one[oneFirstMinIndex] + one[oneSecondMinIndex] )<<endl;
		else if(twos == 2 && ones == 0)
			 cout<<sum - min( one[oneFirstMinIndex] , two[twoFirstMinIndex] + two[twoSecondMinIndex] )<<endl;
		else if(twos == 0 && ones == 2 )
			cout<<sum - min( two[twoFirstMinIndex] , one[oneFirstMinIndex] + one[oneSecondMinIndex] )<<endl;
		else
			cout<<sum - min( one[oneFirstMinIndex] , two[twoFirstMinIndex] + two[twoSecondMinIndex] )<<endl;
	}

}