#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e5+5;
int n,K,q;
bool can[10][15][M];
struct Task{int r,c;}t[N];
unordered_map<int,bool> mp;
vector<int> s[N];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>K>>q;
		int l,x,mxr=0;
		for (int i=1;i<=n;i++)
		{
			cin>>l;
			s[i].clear();
			for (int j=1;j<=l;j++)
			{
				cin>>x;
				s[i].push_back(x);
			}
		}
		mp.clear();
		memset(can,0,sizeof(can));
		for (int i=1;i<=n;i++)
		{
			int lst=-1;
			for (int j=0;j<s[i].size();j++)
			{
				if (s[i][j]==1)
				{
					if (lst!=-1&&j-lst+1<=K)
					{
						mp[1]=1;
						if (i<=10) can[1][i][1]=1;
					}
					lst=j;
				}
				else if (lst!=-1&&j-lst+1<=K)
				{
					if (i<=10) can[1][i][s[i][j]]=1;
					mp[s[i][j]]=1;
				}
			}
		}
		bool flg=1;
		for (int i=1;i<=q;i++)
		{
			cin>>t[i].r>>t[i].c;
			if (t[i].r!=1) flg=0;
			mxr=max(mxr,t[i].r);
		}
		if (flg)
		{
			for (int i=1;i<=q;i++) cout<<mp[t[i].c]<<"\n";
		}
		else
		{
			for (int i=2;i<=mxr;i++)
			{
				for (int p=1;p<=n;p++)
				{
					for (int j=0;j<s[p].size();j++)
					{
						for (int lstp=1;lstp<=n;lstp++)
						{
							if (p==lstp) continue;
							for (int num:s[lstp])
							{
								if (!can[i-1][lstp][num]) continue;
								for (int k=0;k<j;k++)
								{
									if (j-k+1>K) continue;
									if (s[p][k]==num){can[i][p][s[p][j]]=1;break;}
								}
							}
							if (can[i][p][s[p][j]]) break;
						}
					}
				}
			}
			for (int i=1;i<=q;i++)
			{
				bool res=0;
				for (int j=1;j<=n;j++)
					if (can[t[i].r][j][t[i].c]) {res=1;break;}
				cout<<res<<"\n";
			}
		}
	}
	return 0;
}