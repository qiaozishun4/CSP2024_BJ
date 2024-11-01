#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,a[200005],c[200005],vis[200005],bf[2],nc,nw,pre[200005],ns,ne,i,j,tmp;
vector<int>cnt[1000006];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		nw = nc = ans = 0;
		for(i = 1;i<=1000000;i++)cnt[i].clear();
		memset(vis,0,sizeof(vis));
		memset(pre,0,sizeof(pre));
		memset(bf,0,sizeof(bf));
		cin>>n;
		for(i = 1;i<=n;i++)
		{
			cin>>a[i];
			tmp = cnt[a[i]].size();
			if(tmp)
			{
				pre[i] = cnt[a[i]][tmp-1];
				vis[cnt[a[i]][tmp-1]] = 1;
				vis[i] = -1;
			}
			cnt[a[i]].push_back(i);
		}
		for(i = 1;i<=n;i++)
		{
			c[i] = nc;
			if(vis[i] == 1&&a[i]>nw)
			{
				if(a[i+1]!=a[i])
				{
					nc = !nc;
					nw = a[i];
				}
			}
			else if(a[i] == nw)
			{
				c[i] = c[pre[i]];
				if(vis[i] == -1)nw = 0,nc = !nc;
			}
		}
		for(i = 1;i<=n;i++)
		{

			if(bf[c[i]] == a[i])ans+=a[i];
			bf[c[i]] = a[i];
		}
		cout<<ans<<'\n';
	}
}