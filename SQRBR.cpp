#include <iostream>
#include <vector>
#include <string>
using namespace std;
int count;
vector<int> a;

bool isValid(string seq)
{
	char stack[seq.length()];
	for (int i = 0; i < seq.length(); ++i)
	{
		stack[i]='0';
	}
	int ptr=0;
	for (int i = 0; i < seq.length(); ++i)
	{
		if( seq[i] == '['  )
			stack[ptr++] = '[';
		else if(seq[i] == ']' && ptr!=0)
			stack[--ptr] = '0';
		else
			return false;
	}
	if(stack[0]=='0')
		return true;
}
void permutBrackets(char brckts[], string seq, int n, int k)
{
	if(k==0)
	{
		for (int i = 0; i < a.size(); ++i)
		{
			if(seq[a.at(i)-1]!='[')
				return;
		}
		if( isValid(seq) )
		{
			//cout<<seq<<endl;
			count++;
		}	
		return;
	}
	for(int i = 0; i < n; i++)
	{
		string newSeq=seq + brckts[i];
		permutBrackets(brckts, newSeq, n , k-1);
	}
}
int main() 
{
	char brckts[]={'[',']'};	
	int t,n,k,temp;
	cin>>t;
	while(t--)
	{
		a.clear();
		cin>>n>>k;
		count=0;
		for (int i = 0; i < k; ++i)
		{
			cin>>temp;
			a.push_back(temp);
		}
		permutBrackets(brckts, "", sizeof(brckts), 2*n );
		cout<<count<<endl;
	}
	return 0;
}