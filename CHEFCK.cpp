#include <iostream>
#include <math.h>
using namespace std;
long long int A[10000001];
long long int rangeMinimum( long long int l, long long int r)
{
	long long int min = A[l];
	for (long long int i = l+1; i <= r; i++)
	{
		if( A[i] < min )
			min = A[i];
	}
	return min;
}

int main()
{
	long long int N, Q, K, a, b, c, d, e, f, r, s, t, m, L1, La, Lc, Lm, D1, Da, Dc, Dm, sum = 0, prod = 1, L, R;
	cin>>N>>K>>Q;
	cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>A[1]>>L1>>La>>Lc>>Lm>>D1>>Da>>Dc>>Dm;
	for (long long int x = 2; x <= N; x++)
		if((long long int)pow(t,x) % s  <= r)
			A[x] = ((( a%m * A[x-1]%m )%m  * ( a%m * A[x-1]%m )%m )%m + ( b%m * A[x-1]%m )%m + c%m) %m;
		else
			A[x] = ((( d%m * A[x-1]%m )%m  * ( d%m * A[x-1]%m )%m )%m + ( e%m * A[x-1]%m )%m + f%m) %m;

	for ( long long int i = 1; i <= Q; i++)
	{
		L1 = ((La%Lm * L1%Lm)%Lm + Lc%Lm) % Lm;
		D1 = ((Da%Dm * D1%Dm)%Dm + Dc%Dm) % Dm; 
		L = L1 + 1;
		R = ((L + K - 1 + D1) > N)? N : (L + K - 1 + D1);
		long long int x = rangeMinimum( L, R );
		sum += x;
		prod = ((x % 1000000007) * (prod % 1000000007)) % 1000000007;
	}
	cout<<sum<<" "<<prod;
}