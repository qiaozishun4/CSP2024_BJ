#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
const int MAXN = 100010;
int T, n, m, L, V, ans1, ans2;
long long d[MAXN], v[MAXN], a[MAXN], p[MAXN];
int lM[MAXN], rM[MAXN];
int nxt[2][MAXN];
int find(int i, int x) {
	if (x == nxt[i][x]) return x;
	return nxt[i][x] = find(i, nxt[i][x]);
}
struct Op {
	int l, r, v;
	bool gmin;
	bool operator< (const Op &o) const {
		if (gmin) return v < o.v;
		return v > o.v;
	}
};
vector<Op> opm, opM;//对左端点的限制；对右端点的限制
void init() {
	ans1 = ans2 = 0;
	opm.clear();
	opM.clear();
	for (int i = 0; i < 2; i++)
		for (int j = 0; j <= m + 6; j++)
			nxt[i][j] = j;
	for (int i = 0; i <= m; i++)
		lM[i] = 0, rM[i] = m;
}
//0:能够覆盖的区间右端点最小值
//1:能够覆盖的区间左端点最大值
void out(bool cl, double l, bool cr, double r) {
	if (cl) cout << "[";
	else cout << "(";
	cout << l << ","  << r;
	if (cr) cout << "]";
	else cout << ")";
	cout << endl;
}
void handle(int dm, int dM) {
	opM.push_back({0,      dm - 1, dm - 1, true});//所有dm之前的探测器能够全部检测到的范围在[0,dm-1]内
	opm.push_back({dM + 1, m - 1 , dM + 1, false});//所有dM之后的探测器能够全部检测到的范围在[dM+1,L]内
}
void handle(bool cl, double l, bool cr, double r) {
	if (l == floor(l)) if (!cl) l++;
	else l = ceil(l);
	if (r == floor(r)) if (cr) r++;
	else r = ceil(r);
	int m_ = l, M_ = r, dm, dM;
	//整理为[m,M)形式，其中m,M为整数.
	//可以检测到超度的最左侧的探测器为第一个位置不小于m的
	//可以检测到超速的最右侧的探测器为第一个位置大于等于M的前一个
	dm = lower_bound(p, p + m, m_) - p;
	dM = lower_bound(p, p + m, M_) - p - 1;
	if (dm <= dM) {
		ans1++;
		handle(dm, dM);
	/*	cout << "    " << dm << ", " << dM << endl;
		cout << "    [" << p[dm] << "," << p[dM] << "]" << endl;
		cout << "    [" << m_ << "," << M_ << "]" << endl;*/
	}
}
int main() {
	ios::sync_with_stdio(false);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n >> m >> L >> V;
		init();
		for (int i = 0; i < n; i++)
			cin >> d[i] >> v[i] >> a[i];
		for (int i = 0; i < m; i++)
			cin >> p[i];
		sort(p, p + m);
		for (int i = 0; i < n; i++) {
			double l, r;
			bool cl = true, cr = true;//true:端点是闭的
			bool flag = false;//true:区间[l,r]是非空的
			if (a[i] == 0)
				if (v[i] > V) l = d[i], r = L, flag = true;
			if (a[i] > 0)
				if (v[i] > V) l = d[i], r = L, flag = true;
				else l = d[i] + (V * V - v[i] * v[i]) * 0.5 / a[i], r = L, cl = false, flag = (l < r);
			if (a[i] < 0) 
				if (v[i] > V) {
					l = d[i], r = d[i] + (V * V - v[i] * v[i]) * 0.5 / a[i], cr = false, flag = true;
					if (r > L) r = L, cr = true;
				}
			
			if (flag) {
			//	cout << i << " ";out(cl, l, cr, r);
				handle(cl, l, cr, r);
			}
		}
		sort(opm.begin(), opm.end());
		sort(opM.begin(), opM.end());
		for (Op o : opm) {
		//	cout << "lM:" << o.l << " " << o.r << " " << o.v << endl;
			for (int i = o.l - 1; i < o.r;) {
				i = find(0, i + 1);
				if (i <= o.r) lM[i] = o.v;
				nxt[0][i] = o.r + 1;
			}
		}
		for (Op o : opM) {
		//	cout << "rM:" << o.l << " " << o.r << " " << o.v << endl;
			for (int i = o.l - 1; i < o.r;) {
				i = find(1, i + 1);
				if (i <= o.r) rM[i] = o.v;
				nxt[1][i] = o.r + 1;
			//	cout << "rM[" << i << "] = " << o.v << endl;
			}
		}
		int cur = 0;
		while (rM[cur] < m) {
			int nxt = 0;
			for (int i = cur; i < m && lM[i] <= cur; i++)
				nxt = rM[i];
			cur = nxt;
			ans2++;
		}
		cout << ans1 << " " << m - ans2 << endl;
	}
	return 0;
}