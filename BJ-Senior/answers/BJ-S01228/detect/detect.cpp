#include<bits/stdc++.h>
using namespace std;
#define int long long
const int NR = 1e5 + 5;
const int MR = 1e6 + 5;
const int MAX = 1e8;
int t;
int n, m, l, v;
struct Car {
	int d, v, a, vd, cnt;
	bool isvd, vis;
} car[NR];
int p[NR];
int psum[MR], pvis[MR];
struct P {
	int cnt;
	bool box[3005];
} pc[3005];
bool vis[NR];
void init() {
	memset(vis, false, sizeof vis);
	for(int i = 1; i <= 3000; ++i) {
		pc[i].cnt = 0;
		memset(pc[i].box, false, sizeof pc[i].box);
	}
	memset(psum, 0, sizeof psum);
	memset(pvis, 0, sizeof pvis);
}
void solve() {
	init();
	bool A = true, B = true;
	cin >> n >> m >> l >> v, l++;
	for(int i = 1; i <= n; ++i) {
		cin >> car[i].d >> car[i].v >> car[i].a, car[i].d++, car[i].isvd = car[i].vis = false;
		if(car[i].a != 0) A = false;
		if(car[i].a <= 0) B = false;
	}
	for(int i = 1; i <= m; ++i)
		cin >> p[i], p[i]++, pvis[p[i]] = i;
	for(int i = 1; i <= l; ++i) {
		psum[i] = psum[i - 1];
		if(pvis[i] > 0) psum[i]++;
	}
	for(int i = 1; i <= n; ++i) {
		if(car[i].v <= v && car[i].a <= 0) car[i].vd = -1;
		else if(car[i].v > v && car[i].a >= 0) car[i].vd = car[i].d;
		else if(car[i].a > 0) car[i].vd = car[i].d + ((v * v - car[i].v * car[i].v) / (2 * car[i].a)) + 1;
		else if(car[i].a < 0) {
			car[i].vd = car[i].d + (v * v - car[i].v * car[i].v) / (2 * car[i].a);
			if((v * v - car[i].v * car[i].v) % (2 * car[i].a) == 0) car[i].vd--;
		}
		if(car[i].a < 0 && car[i].vd > l) car[i].vd = l;
		if(car[i].a >= 0 && car[i].vd > l) car[i].vd = -1;
	}
	int ans1 = 0;
	for(int i = 1; i <= n; ++i) {
		if(car[i].vd == -1) continue;
		if(car[i].a >= 0 && psum[l] - psum[car[i].vd - 1] > 0)
			car[i].cnt = psum[l] - psum[car[i].vd - 1], car[i].isvd = true, ans1++;
		if(car[i].a < 0 && psum[car[i].vd] - psum[car[i].d - 1] > 0)
			car[i].cnt = psum[car[i].vd] - psum[car[i].d - 1], car[i].isvd = true, ans1++;
	}
	cout << ans1 << " ";
	if(ans1 == 0) {
		cout << m << endl;
		return;
	}
	if(A || B) {
		cout << m - 1 << endl;
		return;
	}
	for(int i = 1; i <= n; ++i) {
		if(!car[i].isvd) continue;
		for(int j = 1; j <= m; ++j) {
			if(car[i].a >= 0 && car[i].vd <= p[j] && p[j] <= l) pc[j].box[i] = true, pc[j].cnt++;
			if(car[i].a < 0 && car[i].d <= p[j] && p[j] <= car[i].vd) pc[j].box[i] = true, pc[j].cnt++;
		}
	}
	int tot = m, ans2 = 0;
	while(tot > 0) {
		ans2++;
		int mxcnt = 0, mxi = 0;
		for(int i = 1; i <= m; ++i) {
			if(pc[i].cnt == 0 && !vis[i]) tot--, vis[i] = true;
			else if(pc[i].cnt > mxcnt) mxi = i, mxcnt = pc[i].cnt;
		}
		for(int i = 1; i <= 3000; ++i) {
			if(pc[mxi].box[i]) {
				for(int j = 1; j <= m; ++j) {
					if(pc[j].box[i]) pc[j].box[i] = 0, pc[j].cnt--;
				}
			}
		}
	}
	cout << m - ans2 + 1 << endl;
}
signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while(t--) solve();
	return 0;
}