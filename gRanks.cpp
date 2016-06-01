#include <bits/stdc++.h>
using namespace std;
struct parti{
	string nam;
	long long int score;
};

bool compr(parti a, parti b){
	if( a.score > b.score)
		return true;
	else if( a.score == b.score )
		return a.nam < b.nam;
	else return false;
}

int main(){
	int t,cases;
	cin>>t;
	cases = t;
	while(t--)
	{
		int P;
		cin>>P;
		long long int p[P];
		for (int i = 0; i < P; ++i)
		{
			cin>>p[i];
		}
		int N;
		cin>>N;
		long long int w[N];
		string name;
		map<string, vector<long long int> > mp;
		for (int i = 0; i < N; ++i)
		{
			cin>>w[i];
			for (int j = 0; j < P; ++j)
			{
				cin>>name;
				long long int prod = w[i] * p[j];
				//cout<<prod<<endl;
				mp[name].push_back(prod);
			}
		}
		int M;
		cin>>M;
		parti o[mp.size()];
		int j = 0;
		for (map<string,vector<long long int> >::iterator it = mp.begin(); it != mp.end(); ++it, ++j)
		{
			sort(it->second.begin(), it->second.end(),greater<int>());
			long long int sum = 0;
			for (int i = 0; i < M && i < it->second.size(); ++i)
			{
				sum += it->second[i];
			}
			o[j].nam = it->first;
			o[j].score = sum;
		}
		//cout<<mp.size()<<endl;
		sort(o,o+mp.size(),compr);
		cout<<"Case #"<<cases-t<<":"<<endl;
		long long int prevRank;
		for (int i = 0; i < mp.size(); ++i)
		{
			if(i > 0 && o[i-1].score != o[i].score)
			{
				cout<<i+1<<": "<<o[i].nam<<endl;
				prevRank = i+1;
			}
			else if(i > 0 && o[i-1].score == o[i].score)
			{
				cout<<prevRank<<": "<<o[i].nam<<endl;
			}
			else if( i == 0 )
			{
				cout<<"1: "<<o[0].nam<<endl;
				prevRank = 1;
			}
		}
	}
}