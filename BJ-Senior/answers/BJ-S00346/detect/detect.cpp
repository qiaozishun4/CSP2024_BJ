#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int d[N], v[N], a[N], p[N];
int n, m, L, V;

struct node {
	int start, end;
	bool operator < (const node &B) const {
		return start == B.start ? end > B.end : start < B.start;
	}
}c[N];

vector<int> choose;
bool tst[N];
int ans2 = -1, st;
void chose(int i, int ans1) {
	if(i == m + 1) {
		memset(tst, 0, sizeof tst);
		// printf("choose: ");
		for(int i : choose) {
			// printf("%d ", i);
			for(int j = st; j <= m; j++) {
				// printf("car %d can be test in %d - %d\n", j, c[j].start, c[j].end);
				if(c[j].start <= i && c[j].end >= i) tst[j] = 1;
			}
		}
		// puts("");
		int tans1 = 0;
		for(int i = st; i <= m; i++) {
			if(tst[i]) tans1++;
		}
		// printf("choose: ");
		// for(int i : choose) printf("%d ", i);
		// printf(" ans = %d ans1 = %d lst=%d\n", tans1, ans1,m - choose.size());
		if(tans1 != ans1) return;
		// printf("pass");
		// printf("pass\n");
		ans2 = max(ans2, m - (int)choose.size());
		return;
	}
	
	chose(i + 1, ans1);

	choose.push_back(p[i]);
	chose(i + 1, ans1);
	choose.pop_back();
}

void solve() {
	ans2 = -1;
	memset(d, 0, sizeof d);
	memset(v, 0 ,sizeof v);
	memset(a, 0, sizeof a);
	scanf("%d%d%d%d", &n, &m, &L, &V);
	for(int i = 1; i <= n; i++) 
		scanf("%d%d%d", &d[i], &v[i], &a[i]);
	for(int i = 1; i <= m; i++) 
		scanf("%d", &p[i]);
	sort(p + 1, p + m + 1, greater<int>());
	//problem 1
	// printf("p[1]=%d\n",p[1]);
	int ans1 = 0;
	double speed, ed;
	bool flag = 0;
	for(int i = 1; i <= n; i++) {
		if(d[i] > p[1]) continue;
		if(a[i] >= 0) ed = p[1];
		else {
			flag = 1;
			int l = 1, r = m;
			while(l < r) {
				int mid = (l + r) >> 1;
				if(p[mid] <= d[i]) r = mid;
				else l = mid + 1;
			}
			if(p[l] < d[i]) l--;
			ed = p[l];
		}
		if(1.0 * (v[i]) * (v[i]) + 2 * a[i] * (ed - d[i]) < 0) continue;
		speed = 1.0 * sqrt(1.0 * (v[i]) * (v[i]) + 2 * a[i] * (ed - d[i]));
		// printf("car %d at %lf's speed = %.2lf\n", i, ed, speed);
		if(speed > V) ans1++;
	}
	printf("%d ", ans1);
	if(!flag) {
		//a >= 0
		if(ans1 == 0) printf("%d\n", m);
		else printf("%d\n", m - 1);
	}else {
		for(int i = 1; i <= n; i++) {
			if(a[i] > 0) {
				c[i].start = min(L, max(0,d[i] + (int)ceil((1.0 * V * V - 1.0 * v[i] * v[i]) / 2.0 / a[i])));
				if(c[i].start == L) c[i].start = -1;
				c[i].end = L;
			}else if(a[i] == 0) {
				if(v[i] > V) c[i].start = d[i];
				else c[i].start = -1;
				c[i].end = L;
			}else if (a[i] < 0) {
				if(v[i] > V) c[i].start = d[i];
				else c[i].start = -1;
				c[i].end = min(L, d[i] + (int)ceil((1.0 * V * V - 1.0 * v[i] * v[i]) / 2.0 / a[i]));
			}
		}
		sort(c + 1, c + n + 1);
		st = 1;
		while(c[st].start == -1) st++;
		// for(int i = st; i <= m; i ++) {
			// printf("car %d can be test in %d - %d\n", i, c[i].start, c[i].end);
		// }
		chose(1, ans1);
		// printf("choose: ");
		// for(int i : choose) printf("%d ", i);
		// puts("");
		printf("%d\n", ans2);
	}
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}