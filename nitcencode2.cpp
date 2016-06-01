#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
int a[1000001];
long int power(long int a, long int n, long int mod)
{
 long int power=a,result=1;

 while(n)
 {
  if(n&1) 
   result=(result*power)%mod;
  power=(power*power)%mod;
  n>>=1;
 }
 return result;
}
bool witness(long int a, long int n)
{
 long int t,u,i;
 long int prev,curr;

 u=n/2;
 t=1;
 while(!(u&1))
 {
  u/=2;
  ++t;
 }
 prev=power(a,u,n);
 for(i=1;i<=t;++i)
 {
  curr=(prev*prev)%n;
  if((curr==1)&&(prev!=1)&&(prev!=n-1)) 
   return true;
  prev=curr;
 }
 if(curr!=1) 
  return true;
 return false;
}
inline bool IsPrime( long int number )
{
 if ( ( (!(number & 1)) && number != 2 ) || (number < 2) || (number % 3 == 0 && number != 3) )
  return (false);

 if(number<1373653)
 {
  for( long int k = 1; 36*k*k-12*k < number;++k)
  if ( (number % (6*k+1) == 0) || (number % (6*k-1) == 0) )
   return (false);

  return true;
 }

 if(number < 9080191)
 {
  if(witness(31,number)) return false;
  if(witness(73,number)) return false;
  return true;
 }

 if(witness(2,number)) return false;
 if(witness(7,number)) return false;
 if(witness(61,number)) return false;
 return true;
}
int main()
{
	long int t,l,r,ans;
	double f;
	cin>>t;
	long int val=0;
	for(long int i=1; i < 1000001 ; i++)
	{
		if(IsPrime(i))
		{
			val++;
		}
		a[i]=val;

	}
	while(t--)
	{
		scanf("%ld%ld",&l,&r);	
		
		if ((IsPrime(l) && IsPrime(r)) || IsPrime(l))
			ans = 1 + a[r] - a[l] ;
		else
			ans = a[r] - a[l]  ;
		
		f=(double)ans/(double)(r-l+1);
		cout << f << '\n';
	}
}