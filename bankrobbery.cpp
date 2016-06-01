#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	int t,m;
	double p;
	cin>>t;
	while(t--){
		cin>>m>>p;
		if(m%2 == 1)
			cout<<"1000000000.0 0.0"<<endl;
		else{
			double two = 1000000000.0 * p;
			cout << setprecision(1) << fixed << 1000000000.0 - two<<" ";
			cout << setprecision(1) << fixed << two<<endl;
		}
	}
}