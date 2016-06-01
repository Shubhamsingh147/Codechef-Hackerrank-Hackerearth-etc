#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	stack<char> st;
	st.push(s[0]);
	for(int i = 1 ; i < s.length(); i++)
	{
		if(st.top() == s[i])
			st.pop();
		else
			st.push(s[i]);
	}
	vector<char> v;
	int x = st.size();
	for (int i = 0; i < x ; ++i)
	{
		v.push_back(st.top());
		st.pop();
	}
	for (int i = 0; i < x; ++i)
	{
		cout<<v[x-1-i];
	}
}