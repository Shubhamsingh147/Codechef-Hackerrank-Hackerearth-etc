#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <map>
using namespace std;
int main(){
	int k;
	cin>>k;
	map<string,bool> rem;
	string dis[k];
	string final;
	char sen[10000];
	for (int i = 0; i < k; ++i)
	{
		cin>>dis[i];
		rem[dis[i]] = true;
	}
	getchar();
	int a;
	cin>>a;
	string word;
	for (int i = 0; i < a; ++i)
	{
		cin>>word;
		if( !rem[word] ){
			final+= toupper(word[0]);
			final+= '.';
		}
	}
	for (int i = 0; i < final.length()-1; ++i)
	{
		cout<<final[i];
	}
}