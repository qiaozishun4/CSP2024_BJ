//HMZ于东方升起，如利剑般驱散黑暗，撒遍光明，化解迷茫，指引道路，构筑世界之真理！
#include <bits/stdc++.h>
using namespace std;
int l[1000005], b[100005];
pair<int, int> a[100005];
bool cmp(pair<int, int> x, pair<int, int> y) {
	return x.second < y.second;
}
int find(int L, int r, int v, int A, int V) {
	int ans = -1;
	int l = L;
	while (l <= r) {
		int mid = (l + r) / 2;
		if ((mid - L) * 2 * A + v * v > V) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}
int find1(int L, int r, int v, int A, int V) {
	int ans = -1;
	int l = L;
	while (l <= r) {
		int mid = (l + r) / 2;
		if ((mid - L) * 2 * A + v * v > V) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N, m, L, V, n = 0;
		cin >> N >> m >> L >> V;
		for (int i = 1; i <= N; i++) {
			int d, v, A;
			cin >> d >> v >> A;
			if (A < 0) {
				int num = find(d, L, v, A, V * V);
				if (num != -1) a[++n] = make_pair(d, num);
			}
			else if (A > 0) {
				int num = find1(d, L, v, A, V * V);
				if (num != -1) a[++n] = make_pair(num, L);
			}
			else {
				if (v > V) {
					a[++n] = make_pair(d, L);
				}
			}
		}
		sort(a + 1, a + 1 + n, cmp);
		// for (int i = 1; i <= n; i++) {
		// 	cout << a[i].first << ' ' << a[i].second << '\n';
		// }
		for (int i = 1; i <= m; i++) cin >> b[i];
		sort(b + 1, b + 1 + m);
		for (int i = 0; i <= L; i++) l[i] = 0;
		for (int i = 1; i <= m; i++) l[b[i]] = i;
		for (int i = 1; i <= L; i++) {
			if (!l[i]) l[i] = l[i - 1];
		}
		int cnt = 0; b[0] = -1;
		int ans1 = 0, ans2 = m;
		for (int i = 1; i <= n; i++) {
			// cout << i << ' ' << a[i].first << ' ' << a[i].second << ' ' << cnt << ' ' << b[cnt] << '\n';
			if (a[i].first <= b[cnt] && a[i].second >= b[cnt]) ans1++;
			else {
				int num = l[a[i].second];
				// cout << i << ' ' << a[i].first << ' ' << a[i].second << ' ' << num << ' ' << b[num] << '\n';
				if (a[i].first <= b[num] && a[i].second >= b[num]) {
					cnt = num;
					ans2--; ans1++;
				}
			}
			// cout << i << ' ' << ans1 << ' ' << ans2 << '\n';
		}
		cout << ans1 << ' ' << ans2 << '\n';
	}
	return 0;
}