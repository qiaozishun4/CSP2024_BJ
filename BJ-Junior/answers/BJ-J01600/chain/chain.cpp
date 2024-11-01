#include <bits/stdc++.h>
using namespace std;
long long s[1005][1005];long long l[1005];
long long n,k,q,r,c;
bool flag=0;
void dfs(long long start/*开始的数*/,long long last/*上个人*/,long long round/*进行轮数*/,long long exp) 
{
	for(long long o=1;o<=n;o++)//枚举人
	{
		if(o==last)continue;
		for(long long stat=1;stat<=l[o];stat++)
		{
			if(s[o][stat]==start)
			{
				for(long long end=stat+1;end<=l[o]&&end-stat+1<=k;end++)
				{
					if(round==r)
					{
						if ((s[o][end]==exp))
						{
							flag=1;
						}
						continue;
					}
					dfs(s[o][end],o,round+1,exp);
				}
			}
		}
	}
}
long long main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	long long t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		for(long long i=1;i<=n;i++)
		{
			cin>>l[i];
			for(long long j=1;j<=l[i];j++)
			{
				cin>>s[i][j];
			}
		}
		while(q--)
		{
			flag=0;
			cin>>r>>c;
			dfs(1,0,1,c);
			cout<<flag<<endl;
		}
	}
	return 0;
}