#include <bits/stdc++.h>

using namespace std;

const int maxn=10000;

map<string,int> hashTable;
int dp[maxn];

int LongestChain(vector<string> V)
{
	vector< pair<int,string> > list;
	for (int i = 0 ; i < V.size(); i++){
		list.push_back(make_pair(V[i].size(),V[i]));
	}
	sort(list.begin(),list.end());	
	int N=list.size();
	hashTable[list[0].second] = 0 ;
	dp[0]=1;

	int answer=dp[0];

	for (int i=1;i<N;i++){
		dp[i]=1;
		string s=list[i].second;
		
		int size = s.size();
		for (int j=0;j<size;j++){
			
			string tmpStr = s;
			tmpStr.erase(tmpStr.begin()+j);
			map<string,int>::iterator it = hashTable.find(tmpStr);

			if (it!=hashTable.end())
				dp[i] = max (dp[i],dp[it->second]+1);
		}
		answer = max ( answer , dp[i]);
		hashTable[s] = i;
	}
	return answer;
}



int main()
{

	int N;
	cin >> N;
	vector<string> V(N);
	for (int i=0;i<N;i++)
		cin >> V[i];
	cout << LongestChain(V) << endl;
	return 0;
}
