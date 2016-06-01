#include <iostream>
#include <stdlib.h>
using namespace std;
#define pata_nahi 2
#define haan 1
#define nahi 0
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		bool confusion = false;
		cin>>n;
		int k[n+1],s[n+1],khud[n+1],gadbad[n+1];
		for (int i = 1; i <= n; ++i)
		{
			cin>>k[i]>>s[i];
			if(k[i] == i && s[i] == 1)
				confusion = true;
			gadbad[i] = pata_nahi;
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int z = 1; z <= n; ++z) khud[z] = 2;
			khud[i] = 0;
			int next = k[i],val = s[i], j = i;
			bool confusion_till_now = false;
			while(!confusion_till_now)
			{
				while (gadbad[j] == pata_nahi)
				{
					next = k[j];
					int temp = (khud[j] == 0) ? s[j] : !s[j];
					if (khud[k[j]] == 2)
					{
						khud[k[j]] = temp;
					}
					else if (khud[k[j]] != temp)
					{
						confusion_till_now = true;
						break;
					}
					j = next;
				}
			}
			if (confusion_till_now)
			{
				confusion = true;
				break;
			}
			gadbad[i] = nahi;
		}

		if(confusion)
			cout<<"Not Intelligent Enough!"<<endl;
		else
			cout<<"Intelligent!"<<endl;
	}
}