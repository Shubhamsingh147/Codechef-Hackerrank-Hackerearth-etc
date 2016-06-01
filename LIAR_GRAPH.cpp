#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        map<int, vector<int> > g;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int k,s;
            cin>>k>>s;
            vector<int> temp;
            temp.push_back(k);
            temp.push_back(s);
            g[i]=temp;
        }
        //cout<<"Hi"<<endl;
        bool checked[n+1];
        int val[n+1];
        for(int i=1;i<=n;i++)
        {
            checked[i]=false;
            val[i]=0;
        }
        int curr=1,total=0;
        bool conf=false;
        while(1)
        {
            //cout<<curr<<" "<<total<<endl;
            //char a;
            //cin>>a;
            if(curr==n&&checked[n]) {break;}
            if(checked[curr]&&(total-val[curr])%2==1)
            {
                conf=true;
                //cout<<"In"<<endl;
                break;
            }
            else
            {
                checked[curr]=true;
                val[curr]=total;
                total+=g[curr][1];
                curr=g[curr][0];
            }
        }
        if(!conf) cout<<"Intelligent!"<<endl;
        else cout<<"Not Intelligent Enough!"<<endl;
    }
}