pair<long long int,vector<long long int> > findSmallerInRight(string str, int low, int high)
{
    long long int countRight = 0, i;
    int alpha[60] = {0};
    alpha[str[low]-'A']++;
    for (i = low+1; i <= high; ++i)
    {
        alpha[str[i]-'A']++;
        if (str[i] < str[low])
            ++countRight;
    }
    vector<long long int> v;
    for( i = 0; i < 60; i++)
    {
        if(alpha[i] > 1)
            v.push_back(alpha[i]);
    }
    
    return make_pair(countRight,v);
}
int inversemod(long long num)
{
	int x=1;
	int m=1000001;
	while(m>0)
	{
		if(m%2==1)
		{
			x=(x*num)%1000003;
		}
		num=(num*num)%1000003;
		m/=2;
	}
	return x;
}

int Solution::findRank(string str)
{
    int mod = 1000003;
    int fact[1000003] = {1};
    for(int i = 1; i < 1000003; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
    int len = str.length();
    long long int mul = fact[len];
    int rank = 1;
    long long int countRight;
    int i;
    for (i = 0; i < len; ++i)
    {
        mul /= len - i;
        long long int rptd = 1;
        pair<long long int,vector<long long int> > val = findSmallerInRight(str, i, len-1);
        countRight = val.first;
        vector<long long int> v = val.second;
        for(int j = 0; j < v.size(); j++)
            rptd = (rptd * fact[v[j]])%mod;
        int invMod = inversemod(rptd);
        cout<<"("<<countRight<<"*"<<mul<<")*"<<invMod<<" + ";
        rank = (rank + ( (countRight * mul)%mod / invMod )%mod)%mod;
    }
    return rank;
}