#include <bits/stdc++.h>
using namespace std;
int n,k,q;
int l[1005],s[1010][2200],ans,r,c;
void dfs(int cur,int last,int p)
{
	if (cur==r+1)
	{
		if (last==c)
			ans=1;
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		if (i==p)
			continue;
		for (int j=1;j<=l[i];j++)
		{
			if (s[i][j]!=last)
				continue;
			for (int len=1;len<k;len++)
			{
				dfs(cur+1,s[i][j+len],i);
				if (ans)
					break;
			}
		}
		if (ans)
			break;
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>k>>q;
		for (int i=1;i<=n;i++)
		{
			cin>>l[i];
			for (int j=1;j<=l[i];j++)
				cin>>s[i][j];
		}
		while (q--)
		{
			cin>>r>>c;
			if (r==1)
			{
				bool flag=0;
				for (int i=1;i<=n;i++)
				{
					for (int j=1;j<=l[i];j++)
					{
						if (s[i][j]!=1)
							continue;
						for (int len=1;len<k;len++)
						{
							if (s[i][j+len]==c)
								flag=1;
							if (flag||j+len==l[i])
								break;
						}
						if (flag)
							break;
					}
					if (flag)
						break;
				}
				cout<<flag<<"\n";
			}
			else
			{
				ans=0;
				dfs(1,1,0);
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}
