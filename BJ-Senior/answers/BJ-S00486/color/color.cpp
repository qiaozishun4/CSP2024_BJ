#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
int a[N];
ll f[2020][2020],c[N],res,vis[N];
vector<int> G[N];
void dfs(int x)
{
	vis[x]=1;
	for(auto to:G[x])
	{
		if(a[to]==a[x])  res+=a[to];
		dfs(to);
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)  cin>>a[i];
		memset(f,0,sizeof(f));
		if(n<=15)
		{
			int ans=0;
			for(int S=0;S<(1<<(n+1));S++)
			{
				int tmp=S;
				for(int i=1;i<=n;i++)  c[i]=tmp%2,tmp/=2;
				int lc0=-1,lc1=-1,res=0;
				for(int i=1;i<=n;i++)
				{
					if(c[i]==0)
					{
						if(a[i]==lc0)  res+=a[i];
						lc0=a[i];
					}
					else
					{
						if(a[i]==lc1)  res+=a[i];
						lc1=a[i];
					}
				}
				ans=max(ans,res);
			}
			cout<<ans<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)  G[i].clear();
			res=0;
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)  if(a[i]==a[j]){G[i].push_back(j);break;}
				if(G[i].size()==0)  G[i].push_back(i+1);
			}
			dfs(1);
			for(int i=1;i<=n;i++)  if(!vis[i]){dfs(i);}
			cout<<res<<endl;
		}
	}
	return 0;
}