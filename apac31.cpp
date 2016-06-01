#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<queue>
#include <fstream>
#include <algorithm>
using namespace std;
int visited[100][100];
int A[100][100];
int ca = 0;
bool issafe(int i,int j,int visited[][100],int n,int m,int A[][100]){
    if(i>=0 && i<n && j>=0 && j<m && visited[i][j]==0 && A[i][j]==1){
        return true;
    }
    else return false;
}
void bfs(int i,int j,int n,int m,int visited[][100],int A[][100]){
    
        visited[i][j]=1;
        int C[]={-1,0,1,0};
        int B[]={0,1,0,-1};
         
        for(int k=0;k<4;k++){
           
            if(issafe(i+C[k],j+B[k],visited,n,m,A) && visited[i+C[k]][j+B[k]]==0){
                
               
                bfs(i+C[k],j+B[k],n,m,visited,A);
               
            }
        }
       
    
   
    
}
int main() {
    
    int t;
    cin>>t;
    for(int test=0;test<t;test++){
        
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            A[i][j]=s[j]-'0';
            visited[i][j]=0;
        }
    }
    int x;
    cin>>x;
    cout<<"Case #"<<test+1<<":"<<endl;
    while(x--){
        char a;
        cin>>a;
        
        if(a=='M'){
            int p,q,z;
            cin>>p>>q>>z;
            A[p][q]=z;
            
        }
        
        else{
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==0 && A[i][j]==1){
                ca++;
            bfs(i,j,n,m,visited,A);
        }
        }
    }
    
    cout<<ca<<endl;
    ca=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=0;
        }
    }
    }   
        }
    }
    
    return 0;
}
