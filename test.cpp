#include <stdlib.h>
#include <iostream>

using namespace std;
bool randIsUnique(int j, int a[],int k){

	bool res = true;
	for(int i = 0; i < k; ++i)
		if(a[i] == j)
			return false;
	return res;
}
int main(int argc, char *argv[])
{
	//random test case generator
	int n;
	bool unique = false;
	if(argc)
		n = argv[1][0]-'0';
	else 
		n = 10;
	if(argc >= 1)
		unique = argv[2][0] - '0';
	time_t waqt;	
	int a[n];
	for(int i = 0; i < n; i++) a[i] = 0;
	srand((unsigned) time(&waqt));
 	cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		int j = rand()%n+1;
		if(unique)
			while(i == j-1 || !randIsUnique(j,a,i))			//comment these 2 lines..
				j = rand()%n+1;								//to remove unique filter
		
		a[i] = j;
		cout<<j<<" ";
	}
	cout<<endl<<endl;
	return 0;
}
