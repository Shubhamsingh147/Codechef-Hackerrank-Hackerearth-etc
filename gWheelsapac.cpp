#include <iostream>
using namespace std;
int main(){
	int t,np,ne,nt,m,cases;
	cin>>t;
	cases = t;
	while(t--){
		cin>>np>>ne>>nt;
		long double pedal[np], extra[ne], tire[nt];
		for (int i = 0; i < np; ++i)
		{
			cin>>pedal[i];
		}
		for (int i = 0; i < ne; ++i)
		{
			cin>>extra[i];
		}
		for (int i = 0; i < nt; ++i)
		{
			cin>>tire[i];
		}
		cin>>m;
		long double p,q;
		cout<<"Case #"<<cases-t<<": "<<endl;
		for (int i = 0; i < m; ++i)
		{
			cin>>p>>q;
			long double val = p/q;
			//cout<<"val = "<<val<<endl;
			bool flag = false;
			for (int j = 0; j < np; ++j)
			{
				for (int k = 0; k < ne; ++k)
				{
					for (int l = 0; l < ne ; ++l)
					{
						if(l!=k)
						{
							for (int pw = 0; pw < nt; ++pw)
							{
								if ( (pedal[j]/extra[k]) * (extra[l]/tire[pw]) == val)
								{
									flag = true;
									break;
								}
							}
						}
						if(flag)
							break;
					}
					if(flag)
						break;
				}
				if(flag)
					break;
			}
			if(flag)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
}