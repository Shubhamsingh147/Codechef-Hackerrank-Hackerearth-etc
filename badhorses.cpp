#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int indexOf(string a, string arr[], int k)
{
	for (int i = 0; i < k; ++i)
		if(arr[i] == a)
			return i;
}
int main()
{
	int t,m;
	cin>>t;
	int testis = t;
	while(t--)
	{
		cin>>m;
		string names[200] = {""};
		pair<string,string> tuples[m];
		string a,b;
		int k;
		for (int i = 0; i < m; ++i)
		{
			cin>>a>>b;
			tuples[i] = make_pair(a,b);
			bool a_present = false, b_present = false;

			for (k = 0; k < 200 && names[k] != ""; ++k)
			{
				if(a == names[k])
					a_present = true;
				
				if(b == names[k])
					b_present = true;
			}
			if(!a_present)
				names[k++] = a;
			if(!b_present)
				names[k++] = b;
		}
		int arr[k][k];

		for (int i = 0; i < k; ++i)
			for (int j = 0; j < k; ++j)
				arr[i][j] = 0;

		for (int i = 0; i < m; ++i)
		{
			arr[ indexOf(tuples[i].first,names,k) ][ indexOf(tuples[i].second,names,k) ] = 1;
			arr[ indexOf(tuples[i].second,names,k) ][ indexOf(tuples[i].first,names,k) ] = 1;
		}

		// for (int i = 0; i < k; ++i)
		// {
		// 	for (int j = 0; j < k; ++j)
		// 		cout<<arr[i][j]<<" ";
		// 	cout<<endl;
		// }
		int colour[k];
		for (int i = 0; i < k; ++i)
		{
			colour[i] = -1;
		}
		colour[0] = 1;
		queue<int> q;
		q.push(0);
		bool bipartite = true;
		while(!q.empty() && bipartite)
		{
			int i = q.front();
			q.pop();
			for (int j = 0; j < k; ++j)
			{
				if(arr[i][j])
				{
					if ( colour[j] == -1 )
					{
						colour[j] = 1 - colour[i];
						q.push(j);
					}
					else if ( colour[i] == colour[j] )
					{
						bipartite = false;
						break;
					}
				}
			}
		}
		if (bipartite)
			cout<<"Case #"<<testis - t<<": Yes\n";
		else
			cout<<"Case #"<<testis - t<<": No\n";
	}
}