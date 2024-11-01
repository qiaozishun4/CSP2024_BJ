#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V,d[100005],v[100005],a[100005],p[100005],ans1;
double getv(int v0,int aa,int s)
{
	return sqrt(1.0*v0*v0+2*aa*s);
}
bool vis[100005];
int dfs(int pos,int cnt)
{
	if(pos>m)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(p[j]<d[i])continue;
				if(vis[j])continue;
				if(getv(v[i],a[i],p[j]-d[i])>V)
				{
					ans++;
					break;
				}
			}
		}
		if(ans==ans1)return cnt;
		return 0;
	}
	vis[pos]=0;
	int a1=dfs(pos+1,cnt);
	vis[pos]=1;
	int a2=dfs(pos+1,cnt+1);
	return max(a1,a2);
}
	
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		ans1=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(p[j]<d[i])continue;
				if(getv(v[i],a[i],p[j]-d[i])>V)
				{
					ans1++;
					break;
				}
			}
		}
		cout<<ans1<<" ";
		cout<<dfs(1,0);
		cout<<"\n";
	}
	return 0;
}
