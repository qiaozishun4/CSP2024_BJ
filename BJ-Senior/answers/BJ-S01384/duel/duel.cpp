# include <bits/stdc++.h>
//# define rit r[i].attack
using namespace std;
int n, cnt;
struct monster {
	int attack;
	bool on, can;
} r[100010];
bool check() {
	for (int i = 1; i <= n; ++i) {
		if (r[i].can && r[i].on) return true;
	}
	return false;
}
bool cmp(monster a, monster b) {
	return a.attack < b.attack;
}
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &r[i].attack);
		r[i].can = true;
		r[i].on = true;
	}
	sort(r+1, r+1+n, cmp);
	while (check()) {
		int mn=1e6, mn2=1e6, mnidx, mn2idx;
		for (int i = 1; i <= n; ++i) {
			//printf("r[%d] : {%d, %d}\n", i, r[i].on, r[i].can);
			if (r[i].on) {
				if (r[i].attack < mn) {
					mn = r[i].attack;
					mnidx = i;
				} else if (r[i].can && r[i].attack > mn && r[i].attack < mn2) {
					mn2 = r[i].attack;
					mn2idx = i;
				}
			}
		}
		if (mn2 == 1e6) break;
		//printf("{1}r[%d]=%d; {2}r[%d]=%d;\n", mnidx, mn, mn2idx, mn2);
		r[mnidx].on = false;
		r[mn2idx].can = false;
	}
	for (int i = 1; i <= n; ++i) {
		if (r[i].on) cnt++;
	}
	cout << cnt;
	return 0;
}
