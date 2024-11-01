#include <bits/stdc++.h>
using namespace std;

int T,n,k,q;
int s[200005],ans[105][200005],siz[200005],r[100005],c[100005];

struct edge
{
	int from,to;
};
vector<edge> g[100005];

void dfs(int r,int maxr,int pre,int from)
{
	if (r>maxr) return ;
	for (int i=0;i<siz[pre];i++)
	{
		if (g[pre][i].from!=from){
			ans[r][g[pre][i].to]=1;
			dfs(r+1,maxr,g[pre][i].to,g[pre][i].from);
		}
	}
}

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&k,&q);
		int maxs=-1;
		for (int i=1;i<=n;i++){
			int l;
			scanf("%d",&l);
			for (int j=1;j<=l;j++)
			{
				scanf("%d",&s[j]);
				maxs=max(maxs,s[j]);
				int t=j-1;
				while (t>=1&&t>=j-k+1){
					edge tmp={i,s[j]};
					g[s[t]].push_back(tmp);
					siz[s[t]]++;
					t--;
				}
			}
		}
		
		int maxr=-1;
		for (int i=1;i<=q;i++){
			scanf("%d%d",&r[i],&c[i]);
			maxr=max(maxr,r[i]);
		}
		
		for (int i=1;i<=n;i++) dfs(1,maxr,1,0);
		for (int i=1;i<=q;i++){
			printf("%d\n",ans[r[i]][c[i]]);
		}
		
		memset(ans,0,sizeof(ans));
		memset(siz,0,sizeof(siz));
		for (int i=1;i<=maxs;i++) g[i].clear();
	}
	return 0;
}

