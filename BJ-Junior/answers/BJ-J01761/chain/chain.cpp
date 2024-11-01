#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=2e5+5;
typedef pair<int,int> PII;
vector<PII> edge[M];
vector<int> a[N];
int l[N];
int ans[M][15];
int n,k,q,mst;
void dfs(int u,int st,int lp)
{
	if(st>mst||ans[u][st]==lp) return;
	ans[u][st]=lp;
	for(PII x:edge[u])
	{
		int v=x.first,id=x.second;
		if(id==lp) continue;
		if(st<mst) dfs(v,st+1,id);
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>q;
		mst=10;
		for(int i=1;i<=M-1;i++)
			for(int j=0;j<=mst;j++)
				ans[i][j]=0;
		for(int i=1;i<=n;i++)
			a[i].clear();
		for(int i=1;i<=M-1;i++)
			edge[i].clear();
		int tt;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
			{
				cin>>tt;
				a[i].push_back(tt);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<l[i];j++)
			{
				for(int c=j+1;c-j+1<=k&&c<l[i];c++)
				{
					int u=a[i][j],v=a[i][c];
					edge[u].push_back({v,i});
				}
			}
		}
		dfs(1,0,-1);
		while(q--)
		{
			int r,x;
			cin>>r>>x;
			if(ans[x][r]>=1) cout<<1<<'\n';
			else cout<<0<<'\n';
		}
	}
	return 0;
}
