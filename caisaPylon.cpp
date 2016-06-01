#include <iostream>
using namespace std;
long long int min(long long int a, long long int b) { return a>b?b:a; }
int main() {
		int n;
		cin>>n;
		long long int a[n+1];
		a[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			cin>>a[i];
		}
		long int paisa = 0;
		long int energy = 0;
		for (int i = 0; i < n; ++i)
		{
			energy += (a[i] - a[i+1]);
			if(energy < 0){
				paisa += (-1 * energy);
				energy = 0;
			}
		}
		cout<<paisa<<endl;
}