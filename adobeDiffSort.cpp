#include <bits/stdc++.h>
using namespace std;
string a,s;
bool comp(char a,char b){
	int x,y;
	for(int i=0;i<26;i++) if(s[i]==a) x=i; else if(s[i]==b) y=i;
	if(x<y) return true;
	return false;
}
int main() {
	int array[26];
    s = "qwertyuiopadsfghjklmnbvcxz";
    cin>>a;
    sort(a.begin(),a.end(),comp);
    cout<<a<<endl;
	return 0;
}