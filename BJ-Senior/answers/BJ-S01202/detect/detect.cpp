#include <bits/stdc++.h>
using namespace std;
long long t, n, m, l, V, p[100006], c[100005], dv[100005], fa, fb, fc;
struct car{
    long long d, v, a;
} ca[100005];
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld%lld%lld", &n, &m, &l, &V);
        fa = fb = fc = 0;
        for(int i = 1; i <= n; i++){
            scanf("%lld%lld%lld", &ca[i].d, &ca[i].v , &ca[i].a);
            if(ca[i].a > 0) fa = 1;
            if(ca[i].a< 0) fb = 1;
        }
        for(int i = 1; i <= m; i++){
            scanf("%lld", &p[i]);
        }
        sort(p +1, p + 1 + m);
        if(fa == 1 && fb == 0){
            int ans = 0;
            for(int i = 1; i <= n; i++){
                if(ca[i].d > p[m]) continue;
                long long v1 = (long long)(ca[i].v * ca[i].v) + (long long)2 * ca[i].a * (p[m] - ca[i].d);
                if(v1 > V * V) ans++;
            }
            printf("%d %lld\n", ans, m - 1);
            continue;
        }
        if(fa == 0 && fb == 0){
            int ans = 0;
            for(int i = 1; i <= n; i++){
                if(ca[i].d > p[m]) continue;
                if(ca[i].v > V) ans++;
            }
            printf("%d ", ans);
            if(ans > 0) printf("%lld\n", m - 1);
            else printf("%lld\n", m);
            continue;
        }

    }
    return 0;
}
