#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

bool matchCharacters(string a,string b)
{
	//cout<<"Matching "<<a<<" and "<<b<<endl;
	vector<int> alphabetsCount(26,0);
	for(int i=0;i<a.length();i++)
	{
		alphabetsCount.at(a[i]-'a')++;
		alphabetsCount.at(b[i]-'a')--;
	}	
	for(int j=0;j<26;j++)
		if(alphabetsCount.at(j)!=0)
			return false;
	return true;
}
int main()
{
	int t,count;
	string s;
	cin>>t;
	while(t--)
	{	
		count=0;
		cin>>s;
		for(int i=0;i<s.length();i++)
		{
			for(int j=i;j<s.length();j++)
			{
				for(int k=0;k<s.length()-(j-i);k++)
				{
					if(k!=i)
					{
						if(matchCharacters ( s.substr(i,j-i+1), s.substr(k,j-i+1) ))
						{
							count++;
							//cout<<"Count becoming "<<count<<endl;
						}
					}
				}
			}
		}
		cout<<count/2<<endl;
	}
}