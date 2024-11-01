#include<iostream>
using namespace std;
const long long N = 1e6 + 5;
long long n, m, L, V;
long long d[N], v[N], a[N], p[N];
long long T;
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%lld", &T);
	while(T --){
		scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
		for(long long i = 1; i <= n; i ++){
			scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
		}
		long long maxp = 0;
		for(long long i = 1; i <= m; i ++){
			scanf("%lld", &p[i]);
			maxp = max(maxp, p[i]);
		}
		long long ans1 = 0;
		for(long long i = 1; i <= n; i ++){
			if(v[i] > V && d[i] <= maxp) ans1 ++;
		}
		if(ans1 == 0){
			printf("%lld %lld\n", ans1, m);
		}
		else printf("%lld %lld\n", ans1, m-1);
	}
	return 0;
}
