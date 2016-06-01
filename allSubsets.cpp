#include <iostream>
#include <string.h>
using namespace std;

void send(string s,int in,string temp)
{
	if(in == s.length())
	{
		cout<<temp<<endl;
		return;
	}
	send(s,in+1,temp);
	send(s,in+1,temp+s[in]);
}
int main()
{
	string s;
	cin>>s;
	send(s,0,"");
}