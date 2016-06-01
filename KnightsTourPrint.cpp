#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int mat[510][510];
int temp[600];
void func(int temp[],int &row1,int &row2,int m,int col1,int col2){
    int count = 0;
    int curr_row1=0,curr_row2=0;
    for(int i=1;i<=m;i++){
        if(temp[i]==0){
            if(curr_row1 == 0)
            	curr_row1 = i;
            curr_row2 = i;
            if(curr_row2-curr_row1 > row2-row1) {
            	row2 = curr_row2; row1 = curr_row1;
            }
        }
        else if(mat[i][col1] != 0 || mat[i][col2] != 0){
            curr_row1 = 0;
        }
    }
   
}
int main() {
    int m,n;char a;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a;
            if(a=='.') mat[i][j] = 0;
            else mat[i][j] = -1;
        }
    }
    long perimeter = 0;
    for(int col1 = 1;col1<n;col1++){

        for(int i=1;i<=m;i++)
            temp[i] = mat[i][col1];
        
        for(int col2 = col1+1;col2<=n;col2++){

            for(int i=1;i<=m;i++)
                temp[i] += mat[i][col2];

            int row1 = 0,row2=0;
            
            func(temp,row1,row2,m,col1,col2);
            if(row2-row1 > 0 && (2*(row2-row1)+2*(col2-col1)) > perimeter)
                {
                	perimeter  = 2*(row2-row1)+2*(col2-col1); 
                }
        }
    }
    if(perimeter!=0)
    	cout<<perimeter;
    else cout<<"impossible";
    return 0;
}