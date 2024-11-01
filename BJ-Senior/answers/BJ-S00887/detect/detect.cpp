#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T, n, m, L, V;
int d[100005], v[100005], a[100005];
struct node {
	double l, r;
	bool operator < (const node &b) const
	{
		return r < b.r;
	}
} car[100005];
int cnt;
double l[100005], r[100005];
int p[100005];
int sum[1000005];
bool have_ce[1000005];
int isjian[1000005];//isjian[i]----ji lu 0 - i bei 
int lowbit(int x)
{
	return x & -x;
}
void add(int x, int s)
{
	while (x <= L) {
		isjian[x] += s;
		x += lowbit(x);
	}
}
int s(int x)
{
	int ans = 0;
	while (x > 0) {
		ans += isjian[x];
		x -= lowbit(x);
	}
	return ans;
}
const double epf = 1e-9;
void work()
{
	memset(have_ce, false, sizeof(have_ce));
	cnt = 0;
	memset(isjian, 0, sizeof(isjian));
	cin >> n >> m >> L >> V;
	L++;
	for (int i = 1; i <= n; i++) {
		cin >> d[i] >> v[i] >> a[i];
		d[i]++;
		if (v[i] > V && a[i] >= 0) {
			l[i] = d[i];
			r[i] = L;
		} else if (v[i] > V && a[i] < 0) {
			l[i] = d[i];
			r[i] = min(1. * L, 1. * (V * V - v[i] * v[i]) / 2. / a[i] + l[i] - epf);
		} else if (v[i] <= V && a[i] <= 0) {
			l[i] = 2e9;
			r[i] = -2e9;
		} else if (v[i] <= V && a[i] > 0) {
			l[i] = d[i] + 1. * (V * V - v[i] * v[i]) / 2. / a[i] + epf;
			r[i] = L;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> p[i];
		p[i]++;
		have_ce[p[i]] = true;
	}
	for (int i = 1; i <= L; i++)
		sum[i] = sum[i - 1] + have_ce[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (l[i] >= d[i] && l[i] <= r[i] && sum[(int)r[i]] - sum[(int)ceil(l[i]) - 1] > 0) {
			ans++;
			car[++cnt].l = l[i];
			car[cnt].r = r[i];
		}
	}
	cout << ans << " ";
	sort(car + 1, car + cnt + 1);
	int id = 0;//yong dao di ji ge ce su yi
	ans = 0;
	for (int i = 1; i <= cnt; i++) {
		if (s(car[i].r) - s(ceil(car[i].l) - 1) > 0)
			continue;
		while (p[id] <= car[i].r && id < m)
			id++;
		ans++;
		int x = id;
		if (p[x] > car[i].r)
			x--;
		add(p[x], 1);
//		cout << car[i].l << ' ' << car[i].r << "\n";
	}
	cout << m - ans << "\n";
//	for (int i = 1; i <= n; i++)
//		cout << l[i] << ' '  << r[i] << endl;
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T--)
		work();
	return 0;
}