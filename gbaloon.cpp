#include<bits/stdc++.h>
using namespace std;

int maxInd(int *a,int size){
	
	return ind;
}

int maxVal(int *a,int size){
	int max=INT_MIN;
	int ind=-1;
	for(int i=0;i<size;i++){
		if(a[i]>max){
			max=a[i];
			ind=i;
		}
	}
	return max;
}

int calcPoss(){
	int n,m,q;
	cin>>n>>m>>q;
	int vel[m];
	for(int i=0;i<m;i++){
		cin>>vel[i];
	}
	int hor[n];
	int hei[n];
	for(int i=0;i<n;i++){
		cin>>hor[i]>>hei[i];
	}

	int tim[n];
	for(int i=0;i<n;i++){
	
		tim[i]=(int)ceil((double)(- hor[i])/ vel[hei[i]]);
		
		if(tim[i]<=0){
			int flag=0;
			for(int j=0;j<m;j++){
				int uptim=INT_MAX;
				int downtim=INT_MAX;

				if(hei[i]-j-1>=0){
					downtim=(int)ceil((double)(- hor[i])/ vel[hei[i]-j-1]); 

					if(downtim<0){
						downtim=INT_MAX;;
					}
					else{
						flag=1;
					}
				}

				if(hei[i]+j+1<m){
					uptim=(int)ceil((double)(- hor[i])/ vel[hei[i]+j+1]); 
					if(uptim<0){
						uptim=INT_MAX;;
					}
					else{
						flag=1;
					}
				}

				if(flag==1){
					tim[i]=min(uptim,downtim);
					if (uptim==tim[i]){
						hei[i]+=j+1;
					}
					else{
						hei[i]-=(j+1);
					}
					q=q-j-1;
					break;
				}


			}
		}
	}
if(q<0){
	return -1;
}
else{
	int flag=0;
	while(q>0){
		flag=0;
		int max=INT_MIN;
		int maxindind=-1;
		for(int i=0;i<size;i++){
			if(tim[i]>max){
				max=tim[i];
				maxind=i;
			}
		for(int j=0;j<m;j++){
				int uptim=INT_MAX;
				int downtim=INT_MAX;

				if(hei[maxind-j]-1>=0){
					downtim=(int)ceil((double)(- hor[maxind])/ vel[hei[maxind]-j-1]); 

					if(downtim<0){
						downtim=INT_MAX;;
					}
					
				}

				if(maxind+j+1<n){
					uptim=(int)ceil((double)(- hor[maxind])/ vel[hei[maxind]+j+1]); 
					if(uptim<0){
						uptim=INT_MAX;;
					}
				}
				if(min(uptim,downtim)<tim[maxind]){
					if(j+1<=q){
						tim[maxind]=min(uptim,downtim);
						q-=(j+1);
						flag=1;
					}	
					break;
				}
			}
			if(flag!=1){
				break;
			}
	}
} 
int main() {
	int t;
	cin>>t;

	int k=0;
	while(k<t){
		cout<<"Case #"<<++k<<": ";
		int k=calcPoss();
		if(k>0)
			cout<<k<<endl;
		else
			cout<<"IMPOSSIBLE"<<endl;
	}
}

