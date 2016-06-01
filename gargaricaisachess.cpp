#include <iostream>
using namespace std;
int n;
int a[2002][2002];
bool aby1[2002][2002];
bool aby2[2002][2002];
bool safeCoords(int x,int y){
	return (0 <= x && x < n && 0 <= y && y < n);
}
void place1(int x, int y){
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			aby1[i][j] = 0;

	int x1 = x,y1 = y;
	while(safeCoords(x1,y1)){
		aby1[x1][y1] = 1;
		x1--;y1--;
	}
	x1 = x;y1 = y;
	while(safeCoords(x1,y1)){
		aby1[x1][y1] = 1;
		x1++;y1--;
	}
	x1 = x;y1 = y;
	while(safeCoords(x1,y1)){
		aby1[x1][y1] = 1;
		x1--;y1++;
	}
	x1 = x;y1 = y;
	while(safeCoords(x1,y1)){
		aby1[x1][y1] = 1;
		x1++;y1++;
	}
}
bool place2Safe(int x, int y, int k, int l){
	
	int k1 = k, l1 = l;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			aby2[i][j] = 0;	
	
	while(safeCoords(k1,l1)){
		if(aby1[k1][l1] == 1)
			return false;
		aby2[k1][l1] = 1;
		k1--;l1--;
	}
	k1 = k;l1 = l;
	while(safeCoords(k1,l1)){
		if(aby1[k1][l1] == 1)
			return false;
		aby2[k1][l1] = 1;
		k1++;l1--;
	}
	k1 = k;l1 = l;
	while(safeCoords(k1,l1)){
		if(aby1[k1][l1] == 1)
			return false;
		aby2[k1][l1] = 1;
		k1--;l1++;
	}
	k1 = k;l1 = l;
	while(safeCoords(k1,l1)){
		if(aby1[k1][l1] == 1)
			return false;
		aby2[k1][l1] = 1;
		k1++;l1++;
	}
	return true;
}
long int count(int x, int y, int k, int l){
	long int paise = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if(aby1[i][j] || aby2[i][j])
				paise += a[i][j];
	return paise;
}
int main() {
	cin>>n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin>>a[i][j];
	long int max = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			place1(i,j);
			for (int k = 0; k < n; ++k)
			{
				for (int l = 0; l < n; ++l)
				{
					if(!aby1[k][l]){
						if(place2Safe(i,j,k,l))
						{
							long int paise = count(i,j,k,l);
							if(paise > max)
							{
								max =  paise;
								x1 = i;
								y1 = j;
								x2 = k;
								y2 = l;
							}
						}
					}
				}
			}
		}
	}
	cout<<max<<endl<<x1+1<<" "<<y1+1<<" "<<x2+1<<" "<<y2+1<<endl;
}