#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <map>
using namespace std;
string s;
int len;
int count1, count2;
map<string,int> mp;
bool alreadyPresent(string newmsg){
    for (map<string,int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        if (it->first == newmsg)
            return true;
    }
    return false;
}
void numofstrs(string newmsg, stack<string> st, string sec)
{
    if(newmsg.length() == len)
    {
        if(!newmsg.compare(s))
        {
            count2++;
        }
        else if(!alreadyPresent(newmsg))
        {
            count1++;
            mp[newmsg] = 1;
        }
        return;
    }
    else 
    {
        if(sec.length() > 0){
            st.push(sec.substr(0,1));
            numofstrs( newmsg, st , sec.substr(1) );
            st.pop();
        }
        if(!st.empty()){
            newmsg += st.top();
            st.pop();
            numofstrs( newmsg, st , sec );
        }
    }
}

int main() {
    cin>>s;
    count1 = count2 = 0;
    len = s.length();
    stack<string> st;
    numofstrs("",st,s);
    cout<<count2<<" "<<count1+1;
    return 0;
}