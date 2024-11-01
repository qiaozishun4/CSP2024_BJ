#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read()
{
	int res=0,op=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		op|=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch))
	{
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return op?-res:res;
}
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
int t,n,m,k,tot,a[200005],b[200005],c[200005],dep[800005],dr[800005],fa[800005],son[800005][2],id[800005],mv[800005];
ll ans[200005],sum[200005],wrz;
bool vis[800005];
void dfs(int u)
{
	if(dep[u])
	{
		mv[son[u][dr[u]]]=max(mv[son[u][dr[u]]],max(mv[u],dep[u]));
		mv[son[u][dr[u]^1]]=max(mv[son[u][dr[u]^1]],mv[u]);
		dfs(son[u][0]);
		dfs(son[u][1]);
	}
}
void cl(int u)
{
	vis[u]=1;
	if(dep[u])
	{
		if(!vis[son[u][0]]) cl(son[u][0]);
		if(!vis[son[u][1]]) cl(son[u][1]);
	}
	else wrz-=u;
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i) c[i]=read();
	while((1<<k)<n) ++k;
	tot=1<<k;
	for(int i=1;i<=(1<<k);++i)
	{
		fa[i]=(1<<k)+(i-1)/2+1;
		son[fa[i]][i&1^1]=i;
	}
	for(int i=1;i<=k;++i)
	{
		string s;
		cin>>s;
		for(int j=1;j<=(1<<(k-i));++j)
		{
			dr[tot+j]=s[j-1]-'0';
			dep[tot+j]=i;
			if(i==k) continue;
			fa[tot+j]=tot+(1<<(k-i))+(j-1)/2+1;
			son[fa[tot+j]][j&1^1]=tot+j;
		}
		tot+=(1<<(k-i));
	}
	dfs(tot);
	t=read();
	while(t--)
	{
		for(int i=1;i<=tot;++i) id[i]=mv[i]=vis[i]=0;
		int X[4];
		for(int i=0;i<4;++i) X[i]=read();
		for(int i=1;i<=n;++i)
		{
			b[i]=a[i]^X[i%4];
		}
		wrz=1;
		int o=1;
		for(int i=1;i<=n;++i)
		{
			while((1<<dep[o])<i)
			{
				o=fa[o];
				dfs(o);
				wrz=((1ll<<dep[o])-i+1)*(i+(1ll<<dep[o]))/2;
			}
			if(!id[o]&&mv[i]<=b[i]) ans[i]=i;
			else ans[i]=ans[i-1];
			id[i]=i;
			if(!vis[i]) cl(i);
			int u=i;
			while(u!=tot&&!id[fa[u]])
			{
				if(son[fa[u]][dr[fa[u]]]==u&&b[id[u]]>=dep[fa[u]])
				{
					id[fa[u]]=id[u];
					u=fa[u];
					if(!vis[u]) cl(u);
					continue;
				}
				if(son[fa[u]][dr[fa[u]]]!=u&&son[fa[u]][1]==u)
				{
					id[fa[u]]=id[u];
					u=fa[u];
					if(!vis[u]) cl(u);
					continue;
				}
				break;
			}
			sum[i]=ans[i]+wrz;
		}
		ll wz=0;
		for(int i=1;i<=m;++i) wz^=i*sum[c[i]];
		write(wz);
		puts("");
	}
	return 0;
}