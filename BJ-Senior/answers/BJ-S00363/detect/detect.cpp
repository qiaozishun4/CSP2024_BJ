#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 10;
long long n,m,T,L,V,p[maxn];
struct jkl{
	long long d,v,a;
}c[maxn];
bool cmp(jkl x,jkl y) {
	return x.d > y.d;
}
struct jkl1{
	long long l,r;
}car[maxn];
bool cmp1(jkl1 x,jkl1 y) {
	return x.r <= y.r;
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&T);
	while (T--) {
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		for (long long i = 1; i <= n; i++) {
			scanf("%lld%lld%lld",&c[i].d,&c[i].v,&c[i].a);
			car[i].l = 1e9;
			car[i].r = 0;
		}
		for (long long j = 1; j <= m; j++) {
			scanf("%lld",&p[j]);
		}
		sort(c + 1, c + 1 + n,cmp);
		sort(p + 1, p + 1 + m,greater<long long>());
		if (n <= 3000 && m <= 3000) {
			long long tot = 0;
			long long ans1 = 0;
			for (long long i = 1; i <= n; i++) {
				int t = 0;
				for (long long j = 1; j <= m; j++) {
					if (c[i].d <= p[j] && 1ll * c[i].v * c[i].v + 1ll * 2 * c[i].a * (p[j] - c[i].d) > 1ll * V * V) {
					if (t == 0) tot++;
						t = 1;
						car[tot].l = min(car[tot].l,j);
						car[tot].r = max(car[tot].r,j);
					}
				}
				ans1 += t;
			}
			if (ans1 == 0) {
				cout << ans1 << " " << m << endl;
				continue;
			}
			sort(car + 1, car + 1 + tot,cmp1);
			long long ans2 = 1,num = car[1].r;
			for (long long i = 2; i <= tot; i++) {
				if (num < car[i].l) {
					ans2++;
					num = car[i].r;
				}
			}
			cout << ans1 << " " << m - ans2 << endl;
		} else {
			long long ans1;
			ans1 = 0;
			for (long long i = 1; i <= n; i++) {
				if (c[i].d <= p[1] && 1ll * c[i].v * c[i].v + 1ll * 2 * c[i].a * (p[1] - c[i].d) > 1ll * V * V) {
					ans1++;
				} 
			}
			if (ans1 == 0) cout << ans1 << " " << m << endl;
			else cout << ans1 << " " << m - 1 << endl;	
		}
	}
	return 0;
}
