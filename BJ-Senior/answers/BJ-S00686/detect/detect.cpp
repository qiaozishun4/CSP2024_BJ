#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const double eps = 1e-4;

int t, n, m, l, d[100005], v[100005], a[100005], ans, sum;
double p[100005];
double speed;
struct node{int l, r;}q[100005];
bool cmp(node x, node y)
{
	if (x.r != y.r) return x.r < y.r;
	return x.l <= y.l; 
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		ans = 0;
		memset(d, 0, sizeof(d));
		memset(v, 0, sizeof(v));
		memset(a, 0, sizeof(a));
		memset(p, 0, sizeof(p));
		cin >> n >> m >> l >> speed;
		for (int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
		for (int i = 1; i <= m; i++) cin >> p[i];
		p[m + 1] = 2e9;
		for (int i = 1; i <= n; i++)
		{
			//cout << q[i - 1].l << " " << q[i - 1].r << endl;
			//cout << ans << endl;
			//求超速距离区间->求超速测速杆区间(左闭右bi)
			if (a[i] == 0)
			{
				//cout << "1======================" << endl;
				if (v[i] > speed)
				{
					if (d[i] > p[m]) continue;
					else {
						ans++;
						q[i].l = lower_bound(p + 1, p + m + 1, d[i]) - p, q[i].r = m;
					}
				}
			}
			if (a[i] > 0)
			{
				
				double dis = ((speed * speed) - (v[i] * v[i])) / 2.0 / a[i];
				//cout << dis << endl;
				if (dis + d[i] > l) continue;
				if (d[i] > p[m]) continue;
				if (dis <= 0){
					ans++;
					q[i].l = lower_bound(p + 1, p + m + 2, dis) - p, q[i].r = m;
				}
				else{
					//cout << "2======================" << endl;
					//cout << d[i] + dis << endl;
					ans++;
					int pos = lower_bound(p + 1, p + m + 2, d[i] + dis + eps) - p;
					q[i].l = pos, q[i].r = m;
				}
			}
			if (a[i] < 0)
			{
				//cout << "3======================" << endl;
				double dis = ((1.0 * speed * speed) - (v[i] * v[i])) / 2.0 / a[i];
				//cout << dis << endl;
				if (d[i] > p[m]) continue;
				if (dis <= 0) continue;
				else{
					//cout << d[i] << " " << d[i] + dis << endl;
					int pos1 = lower_bound(p + 1, p + m + 2, d[i]) - p;
					int pos2 = lower_bound(p + 1, p + m + 2, d[i] + dis) - p;
					//cout << pos1 << pos2 << " " << p[pos1] << " " << p[pos2] << endl;
					if (abs(p[pos1] - dis) >= eps && pos1 == pos2) continue;
					ans++;
					q[i].l = pos1;
					q[i].r = pos2 - ((p[pos2] - d[i] - dis >= eps) ? 1 : 0);
					//cout << q[i].l << " " << q[i].r << " " << i << endl;
				}
			}
		}
		//cout << "==========";
		cout << ans << " ";
		sort(q + 1, q + n + 1, cmp);
		sum = 0;
		int x = 0;
		for (int i = 1; i <= n; i++)
		{
			if (q[i].l <= x) continue;
			sum++;
			x = q[i].r;
		}
		cout << m - sum << endl;
	}
	return 0;
}