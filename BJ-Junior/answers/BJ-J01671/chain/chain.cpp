#include <bits/stdc++.h>
using namespace std;
int T,n,k,q,r,expect;
int length[1005], S[1005][1005];
bool tr(int round, int player, int number)
{
	if (round==0) return (number==expect);
	for (int p=0;p<n;p++)
	{
		if (p!=player)
		{
			for (int i=0;i<length[p];i++)
			{
				if (S[p][i]==number)
				{
					for(int j=i+2;j<min(length[p],i+k);j++)
					{
					    if (tr(round-1,p,S[i][j])) return true;
			    	}
				}
			}
		}
	}
}
int main()
{
	freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
	
	cin>>T;
	for (int tt=0;tt<T;tt++)
	{
		cin>>n>>k>>q; // the number of players, the max length, the number of questions
		for(int i=0;i<n;i++)
		{
			cin >> length[i];
			for (int j=0;j<length[i];j++) cin>>S[i][j];
		}
		for(int i=0;i<q;i++)
		{
			cin>>r>>expect; // round, the expected number
			cout << (tr(r,-1,1)==1) << endl;
		}
	}
	return 0;
} 





