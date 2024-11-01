# include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int m, p[N], sel[N];

struct Car {
	int d, v, a;
} car[N];

struct Ex_Car {
	int num, l, r;
	bool operator < (const Ex_Car &b) const {
		if (l ^ b.l) return l < b.l;
		return r < b.r;
	}
} ex_car[N];

double getv(int v0, int x, int a){
	return sqrt(max(((a * x) << 1) + v0 * v0, 0));
}

int lwbd(double x){
	int l = 1, r = m;
	while (l < r){
		int mid = (l + r) >> 1;
		if (p[mid] < x) l = mid + 1;
		else r = mid;
	}
	return l;
}

double getx(int v0, int vend, int a){
	if (!a) return 0;
	return (vend * vend - v0 * v0) / (a << 1);
}

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		sel[0] = 0;
		int n, L, V;
		cin >> n >> m >> L >> V;
		for (int i = 1; i <= n; i++) cin >> car[i].d >> car[i].v >> car[i].a;
		for (int i = 1; i <= m; i++) cin >> p[i];
		int ans = 0;
		for (int i = 1; i <= n; i++){
			if (car[i].d > p[m]) continue;
			else {
				if (car[i].a >= 0){
					int x = p[m] - car[i].d;
					if (getv(car[i].v, x, car[i].a) > V){
						ans++;
						ex_car[ans].num = i;
						ex_car[ans].l = p[lwbd(car[i].d + max(getx(car[i].v, V, car[i].a), (double)0))];
						ex_car[ans].r = p[m];
					}
				}
				else {
					double tot_x = getx(car[i].v, 0, car[i].a);
					int near_p = p[lwbd(car[i].d)];
					int x = near_p - car[i].d;
					if (tot_x < x) continue;
					if (getv(car[i].v, x, car[i].a) > V){
						ans++;
						ex_car[ans].num = i;
						ex_car[ans].l = near_p;
						int p_reach_V = lwbd(car[i].d + max(getx(car[i].v, V, car[i].a), (double)0));
						if (getv(car[i].v, p[p_reach_V] - car[i].d, car[i].a) <= V) p_reach_V--;
						ex_car[ans].r = p[p_reach_V];
					}
				}
			}
		}
		cout << ans << ' ';
		sort(ex_car + 1, ex_car + ans + 1);
		for (int i = ans; i >= 1; i--){
			if (!sel[0] || sel[sel[0]] > ex_car[i].r) sel[++sel[0]] = ex_car[i].l;
		}
		cout << m - sel[0] << endl;
	}
	return 0;
}