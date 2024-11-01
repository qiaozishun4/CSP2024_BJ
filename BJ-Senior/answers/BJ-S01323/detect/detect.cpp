#include <bits/stdc++.h>
using namespace std;
#define int long long 
int d[100005];
int v[100005];
int a[100005];
int p[100005];
int vis[3005][3005];
int ans2=INT_MAX;
int ischaosu[3005];
		int n,m,l,V;
int tmp[3005];
void dfs(int x,int cnt)
{
	if(x==m+1)
	{
		int ishefa=1;
		for(int i=1;i<=n;i++)
		{
			if(ischaosu[i]&&!tmp[i])
			{
				ishefa=0;
			}
		}
		if(ishefa)
		{
			ans2=min(ans2,cnt);
		}
		return;
	}
	dfs(x+1,cnt);
	for(int i=1;i<=n;i++)
	{
		tmp[i]+=vis[x][i];
	}
	dfs(x+1,cnt+1);
	for(int i=1;i<=n;i++)
	{
		tmp[i]-=vis[x][i];
	}

}
signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(ischaosu,0,sizeof(ischaosu));
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			int flag=0;
			for(int j=1;j<=m;j++)
			{
				if(d[i]>p[j])continue;
				int s=pow(v[i],2)+2*a[i]*(p[j]-d[i]);
				if(s<0)continue;
				if(1.0*sqrt(s)>V)
				{
					flag=1;
					vis[j][i]=1;
					ischaosu[i]=1;
					// break;
				}
			}
			cnt+=flag;
		}
		ans2=INT_MAX;
		dfs(1,0);
		cout<<cnt<<" "<<m-ans2<<endl;
		// cout<<t<<endl;
	}
	return 0;
}