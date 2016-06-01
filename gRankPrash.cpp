#include <bits/stdc++.h>
using namespace std;
int t,p,w,n,m;
vector<int> s; 
map<string,map<int,int> > fin;
map<int,vector<string> > mp;
int wt;vector<string> vc;
int main(){
	cin>>t;
	for(int z=1;z<=t;z++){
		scanf("%d",&p);
		for(int i=0;i<p;i++){int a; scanf("%d",&a);s.push_back(a);}
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&w);
			for(int j=0;j<p;j++){
				string str;
				cin>>str;
				fin[str][-1*w*s[j]]++;
			}
		}
		scanf("%d",&m);
		map<string,map<int,int> >::iterator it;
		// for(it = fin.begin();it!=fin.end();++it){
		// 	cout<<it->first<<" ";
		// 	for(map<int,int>::iterator it1 = (it->second).begin();it1!=(it->second).end();++it1){
		// 		cout<<it1->first<<" "<<it1->second<<"    ";
		// 	}
		// 	cout<<endl;
		// }
		for(map<string,map<int,int> >::iterator it = fin.begin();it!=fin.end();++it){
			string name = it->first;
			wt = 0;
			int k = 0;
			for(map<int,int>::iterator it1 = (it->second).begin();it1!=(it->second).end();++it1){
				if(k>=m) break;
				while(k<m && it1->second--){
					wt += it1->first;
					k++;
				}
			}
			mp[wt].push_back(name);
		}
		int count = 1;
		printf("Case #%d:\n",z);
		for(map<int,vector<string> >::iterator it=mp.begin();it!=mp.end();it++){
			for(vector<string>::iterator it1=(it->second).begin();it1!=(it->second).end();++it1){
				cout<<count<<": "<<*it1<<endl;
				
			}
			count++;
		}
		fin.clear();
		mp.clear();
		vc.clear();
		s.clear();
	}
}