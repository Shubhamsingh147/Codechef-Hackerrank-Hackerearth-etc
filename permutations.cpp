#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
int cont;
void permut(int k,int m,string s)
{
	if(k == m)
	{
		cont++;
		cout<<cont<<") "<<s<<endl;
		v.push_back(s);
	}
	else
	{

		char temp;
		for (int i = k; i <= m; ++i)
		{
			//swap(k,i);
			temp = s[k];
			s[k] = s[i];
			s[i] = temp;

			permut(k+1,m,s);
			
			//swap(i,k);
			temp = s[k];
			s[k] = s[i];
			s[i] = temp;
		}
	}
}
int main()
{
	cont = 0;
	char *name = (char*)malloc(100);
	cin>>name;
	sort(name,name+strlen(name));
	permut(0,strlen(name)-1,name);
	sort(v.begin(),v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<i+100<<") "<<v[i]<<endl;
	}
}