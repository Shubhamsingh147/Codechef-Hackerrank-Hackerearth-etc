#include <bits/stdc++.h>
using namespace std;


int main() {
    int t,i,h,test,m,s,D,hourFirst,minFir,sec,hourSecond,minSec,secSec,hourDiff,minDiff,secDiff,t3,l;
    char G[8],W[8],H[8],B[8],X[8];
    cin>>test;
    for (int i = 1; i <= test; ++i)
    {
        cin>>G>>W>>H>>B>>X>>D;
        h=(X[0]-'0')*10+(X[1]-'0');
        m=(X[3]-'0')*10+(X[4]-'0');
        s=(X[6]-'0')*10+(X[7]-'0');
        t=h*3600+m*60+s;
        hourFirst=(W[0]-'0')*10+(W[1]-'0');
        minFir=(W[3]-'0')*10+(W[4]-'0');
        sec=(W[6]-'0')*10+(W[7]-'0');
        hourSecond=(H[0]-'0')*10+(H[1]-'0');
        minSec=(H[3]-'0')*10+(H[4]-'0');
        secSec=(H[6]-'0')*10+(H[7]-'0');
        if(secSec >= sec && minSec >= minFir && hourSecond >= hourFirst)
        {
            secDiff = secSec - sec;
            minDiff = minSec - minFir;
            hourDiff = hourSecond - hourFirst;
        }
        else
        {
            if(sec > secSec)
            {
                secDiff = 60 - sec;
                minFir++;
                secDiff += secSec;
            }
            else
                secDiff=secSec-sec;
            if(minFir>minSec)
            {
                minDiff=60-minFir;
                hourFirst=hourFirst+1;
                minDiff=minDiff+minSec;
            }
            else
                minDiff=minSec-minFir;
            hourDiff=hourSecond-hourFirst;
        }
        t3=hourDiff*3600+minDiff*60+secDiff;
        if(t3>=t)
        {
            cout<<"Case #"<<i<<": -1"<<endl;
            continue;
        }
        hourFirst = (B[0]-'0')*10 + (B[1]-'0');
        minFir = (B[3]-'0')*10 + (B[4]-'0');
        sec = (B[6]-'0')*10 + (B[7]-'0');
        hourSecond = (G[0]-'0')*10 + (G[1]-'0');
        minSec = (G[3]-'0')*10 + (G[4]-'0');
        secSec = (G[6]-'0')*10 + (G[7]-'0');
        
        if(sec!=0)
        {
            secDiff=60-sec;
            minFir++;
            secDiff+=secSec;
        }
        else
            secDiff=secSec;
        if(minFir!=0)
        {
            minDiff=60-minFir;
            hourFirst=hourFirst+1;
            minDiff=minDiff+minSec;            
        }
        else
            minDiff=minSec;
        if(hourFirst!=24)
            hourDiff=24-hourFirst+hourSecond;
        else
            hourDiff=hourSecond;
        t3=hourDiff*3600+minDiff*60+secDiff;
        if(t3>=t)
        {
            cout<<"Case #"<<i<<": -1"<<endl;
            continue;
        }
        D=D*24*3600;
        l=D/t;
        if(t<43200)
            l++;
        cout<<"Case #"<<i<<": "<<l<<endl;
    }
    return 0;
}