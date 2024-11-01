#include<bits/stdc++.h>
using namespace std;
#define int long long
int Sssd(int d, int v, int a, int p)
{
	int s = p - d;
	return v * v + a * s * 2;
}
int d[100010], v[100010], a[100010];
int p[100010];
int l[100010], r[100010];
signed main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, l, vv;
		cin >> n >> m >> l >> vv;
		int cs = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> d[i] >> v[i] >> a[i];
		}
		for(int j = 1; j <= m; j++)
		{
			cin >> p[j];
		}
		for(int i = 1; i <= n; i++)
		{
			if(d[i] > p[m])
			{
				continue;
			}
			if(Sssd(d[i], v[i], a[i], p[m]) > vv * vv)
			{
				cs++;
			}
		}
		cout << cs << " " << (m - bool(cs)) << endl;
	}
	return 0;
}