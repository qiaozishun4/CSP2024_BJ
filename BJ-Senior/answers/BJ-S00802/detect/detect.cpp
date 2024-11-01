#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e5 + 7;
int n, m, L, V, cnt1, tot1;
int tot, ans;
int p[N], tr[N * 10];

struct Node{
	int d, v, a;
	int l, r, op;
}c[N];

void Cal(int x){
	if(c[x].a == 0){
		if(c[x].v <= V){
			c[x].op = -1;
			return;
		}else{
			c[x].l = c[x].d;
			c[x].r = L; c[x].op = 1;
			return;
		}
	}else if(c[x].a > 0){
		if(c[x].v > V){
			c[x].l = c[x].d; c[x].r = L; c[x].op = 1;
			return;
		}
		if(1ll * (V * V - c[x].v * c[x].v) % (2ll * c[x].a) == 0){
			ll tmpl = (V * V - c[x].v * c[x].v) / (2ll * c[x].a) + 1 + c[x].d;
			if(tmpl > L){
				c[x].op = -1;
				return;
			}else{
				c[x].l = tmpl; c[x].r = L; c[x].op = 1;
				return;
			}
		}else{
			ll tmpl = (ll)ceil((ld)1 *(V * V - c[x].v * c[x].v) / (2ll * c[x].a)) + c[x].d;
			if(tmpl > L){
				c[x].op = -1;
				return;
			}else{
				c[x].l = tmpl; c[x].r = L; c[x].op = 1;
				return;
			}
		}
	}else{
		if(c[x].v <= V){
			c[x].op = -1;
			return;
		}
		if(1ll * (V * V - c[x].v * c[x].v) % (2ll * c[x].a) == 0){
			ll tmpr = (V * V - c[x].v * c[x].v) / (2ll * c[x].a) - 1 + c[x].d;
			c[x].l = c[x].d; c[x].r = (int)min(tmpr, (ll)L); c[x].op = 1;
			return;
		}else{
			ll tmpr = (ll)floor((ld)1 *(V * V - c[x].v * c[x].v) / (2ll * c[x].a)) + c[x].d;
			c[x].l = c[x].d; c[x].r = (int)min((ll)L, tmpr); c[x].op = 1;
			return;
		}
	}
}

struct Ed{
	int l, r;
	bool operator<(const Ed & ed)const{
		if(l == ed.l) return r < ed.r;
		return l < ed.l;
	}
}gt[N], g[N];

int lowbit(int x) { return x & -x;}

void Add(int x){
	for(; x <= L + 1; x += lowbit(x)) tr[x]++;
}

int Ask(int x){
	if(x < 0) return 0;
	int res = 0;
	for(; x; x -= lowbit(x)) res += tr[x];
	return res;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("detect.in", "r", stdin); freopen("detect.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m >> L >> V;
		memset(tr, 0, sizeof(tr));
		for(int i = 1; i <= n; ++i) cin >> c[i].d >> c[i].v >> c[i].a;
		for(int i = 1; i <= m; ++i) cin >> p[i], p[i]++, Add(p[i]);
		for(int i = 1; i <= n; ++i) Cal(i);
		cnt1 = 0; L++; tot1 = 0; tot = 0;
		for(int i = 1; i <= n; ++i){
			if(c[i].op == 1){
				c[i].l++; c[i].r++; c[i].d++;
				if(Ask(c[i].r) - Ask(c[i].l - 1) > 0){
					cnt1++;
					gt[++tot1].l = c[i].l; gt[tot1].r = c[i].r;
				}
			}
		}
		cout << cnt1 << " ";
		sort(gt + 1, gt + tot1 + 1);
		int minn = 1e9 + 7;
		for(int i = tot1; i >= 1; --i){
			if(minn > gt[i].r){
				g[++tot].l = gt[i].l;
				g[tot].r = gt[i].r;
			} 
			minn = min(minn, gt[i].r);
		}
		sort(g + 1, g + tot + 1);
		//for(int i = 1; i <= tot; ++i) cout << g[i].l << " " << g[i].r << endl;
		sort(p + 1, p + m + 1);
		ans = 0;
		int now = 0, lst = -1;
		for(int i = 1; i <= tot; ++i){
			while(now < m && p[now + 1] <= g[i].r) now++;
			if(g[i].l > lst){
				ans++;
				//cout << now << endl;
				lst = p[now];
			}
		}
		cout << m - ans << endl;
	}
	return 0;
}