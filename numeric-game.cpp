#include <iostream>
using namespace std;
bool dp[1002][1002];
bool calculate(int a,  int b){
	if(b%a == 0 && b/a >= 2)
	{
		return true;
	}
	bool flag = false;
	for(int i = 1; i <= b/a; i++)
	{
		for(int j = 1; j <= (b-i*a)/a; j++)
		{
			if( ((b-i*a)-j*a) && a%((b-i*a)-j*a) == 0)
			{			
				if(!(a/((b-i*a)-j*a)) == 0)
					return true;
			}
		}
	}
	return flag;
}
int main()
{
    int t,cases;
    cin>>t;
    cases = t;
	for(int a = 1; a <= 10; a++)
	{
		for(int b = 12; b <= 30; b++)
		{
			//cout<<"a"<<a<<"b"<<b<<endl;
			if(calculate(a,b))
				dp[a][b] = true;
		}
	}
    while(t--)
    {
    	int a1,a2,b1,b2;
    	cin>>a1>>a2>>b1>>b2;
    	int count = 0;
    	
    	for (int i = a1; i <= a2; ++i)
    	{
    		for (int j = b1; j <= b2; ++j)
    		{
    			if(dp[i][j])
    				count++;
    		}
    	}
    	cout<<"Case #"<<cases-t<<": "<<count<<endl;
    }
    return 0;
}