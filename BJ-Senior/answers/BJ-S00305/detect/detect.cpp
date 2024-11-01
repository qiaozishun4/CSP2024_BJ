#include <bits/stdc++.h>
using namespace std;
#define int long long

int t,n,m,l,V,d[100005],v[100005],a[100005],p[100005],mx = 0;
int f[100005],vis[100005];

void dfs(int x,int cnt)
{
	if (x > m)
	{
		for (int i = 1;i <= n;i++)
		{
			int flag = 0;
			for (int j = 1;j <= m;j++)
			{
				if (f[j] == 1) continue;
				if (p[j] < d[i]) continue;
				double vv = sqrt(1.0*v[i]*v[i]+2.0*a[i]*(p[j]-d[i]));
				if (vv > V) 
				{
					flag = 1;
					break;
				}
				if (vv <= 0) break;
			}
			if (flag != vis[i]) return;
		}
		mx = max(mx,cnt);
		return;
	}
	f[x] = 1;
	dfs(x+1,cnt+1);
	f[x] = 0;
	dfs(x+1,cnt);
}

void work()
{
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (p[j] < d[i]) continue;
			double vv = sqrt(1.0*v[i]*v[i]+2.0*a[i]*(p[j]-d[i]));
			if (vv > V) 
			{
				ans++;
				vis[i] = 1;
				break;
			}
			if (vv <= 0) break;
		}
	}
	cout << ans << " ";
	dfs(1,0);
	cout << mx << "\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	while (t--)
	{
		memset(f,0,sizeof f);
		memset(vis,0,sizeof vis);
		mx = 0;
		cin >> n >> m >> l >> V;
		for (int i = 1;i <= n;i++)
		{
			cin >> d[i] >> v[i] >> a[i];
		}
		for (int i = 1;i <= m;i++)
		{
			cin >> p[i];
		}
		if (n <= 20 && m <= 20)
		{
			work();
		}
		else if (a[1] == 0)
		{
			int mx = 0;
			for (int i = 1;i <= m;i++) mx = max(mx,p[i]);
			int ans = 0;
			for (int i = 1;i <= n;i++)
			{
				if (mx >= d[i] && v[i] > V) ans++;
			}
			if (ans == 0) cout << 0 << " " << m << "\n";
			else cout << ans << " " << m-1 << "\n";
		}
		else
		{
			int mx = 0;
			for (int i = 1;i <= m;i++) mx = max(mx,p[i]);
			int ans = 0;
			for (int i = 1;i <= n;i++)
			{
				if (d[i] > mx) continue;
				double s = (V*V-v[i]*v[i])*1.0/(2.0*a[i]);
				if (d[i]+s < mx) ans++;
			}
			if (ans == 0) cout << 0 << " " << m << "\n";
			else cout << ans << " " << m-1 << "\n";
		}
	}
	
	return 0;
}
