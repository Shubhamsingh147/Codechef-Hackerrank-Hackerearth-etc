#include<iostream>
#include <algorithm>
using namespace std;

int rotation(string a)
{
    int n=a.length(),count=1;
    string orig=a;
    for(int i=0;i<n-1;i++)
    {
        rotate(a.begin(),a.begin()+1,a.end());
        if(a==orig){count++;}
    }
    return count;
}

int main()
{
    int t;
    string a,b,c;
    int l1,l2,hash1,hash2,count,num;
    cin>>t;
    while(t--)
    {
        
        cin>>a>>b;
        num=rotation(b);
        //cout<<num<<endl;
        l1=a.length();l2=b.length();hash1=0;hash2=0;count=0;
        if(l1>=l2)
        {
            for(int i=0;i<l2;i++) hash1=hash1+b[i];
            c=b+b;
            for(int i=0;i<l2;i++) hash2=hash2+a[i];
            for(int i=l2;i<=l1;i++)
            {
                if(hash1==hash2)
                {
                    if(c.find(a.substr(i-l2,l2))!=string::npos) count+=num;
                    else cout<<"No"<<endl;
                }
                hash2=hash2-a[i-l2]+a[i];
            }
        }
        cout<<count<<endl;
    }
    
}