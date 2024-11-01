#include <bits/stdc++.h>
using namespace std;
int hs[300][300];
char a[100]={'0','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		char x,y;
		cin>>x>>y;
		hs[(int)x][(int)y]=1;
	}
	for (int i=1;i<=13;i++)
	{
		if (hs[(int)'D'][(int)a[i]]==1)
		{
			cnt++;
		}
		if (hs[(int)'C'][(int)a[i]]==1)
		{
			cnt++;
		}
		if (hs[(int)'H'][(int)a[i]]==1)
		{
			cnt++;
		}
		if (hs[(int)'S'][(int)a[i]]==1)
		{
			cnt++;
		}
	}
	if (52-cnt>=0)
	{
		cout<<52-cnt;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
