#include<bits/stdc++.h>
using namespace std;

const int maxn = 200000;

int d[maxn], a[maxn], v[maxn], p[maxn], cx[30][30];

bool cpr(int x, int y, int all) {
    for(int i = 1;i <= all;i++) {
        if(cx[x][i] < cx[y][i]) return false;
    }
    return true;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        bool aok = true, bok = true, cok = true;
        int n, m, l, vm;
        scanf("%d%d%d%d", &n, &m, &l, &vm);
        for(int i = 1;i <= n;i++) {
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
            if(a[i] != 0) aok = false;
            if(a[i] <= 0) bok = false;
            if(a[i] >= 0) cok = false;
        }
        for(int i = 1;i <= m;i++) scanf("%d", &p[i]);
        if(aok == true) {
            int ansa = 0;
            for(int i = 1;i <= n;i++) {
                if(v[i] > vm) {
                    if(d[i] <= p[m]) ansa++;
                }
            }
            if(ansa == 0) printf("0 %d\n", m);
            else printf("%d %d\n", ansa, m - 1);
        }else if(bok == true) {
            int ansa = 0;
            for(int i = 1;i <= n;i++) {
                if(vm >= v[i]) {
                    long double x = (vm * vm - v[i] * v[i]) / 2.0 / a[i];
                    long double x1 = d[i] + x;
                    if(x1 >= l) continue;
                    if(x1 < p[m]) ansa++;
                } else {
                    if(d[i] <= p[m]) ansa++;
                }
            }
            if(ansa == 0) printf("0 %d\n", m);
            else printf("%d %d\n", ansa, m - 1);
        }else{
            memset(cx, 0, sizeof(cx));
            int ansa = 0;
            for(int i = 1;i <= n;i++) {
                bool ok = false;
                if(a[i] == 0) {
                    if(v[i] > vm) {
                        for(int j = 1;j <= m;j++) {
                            if(p[j] >= d[i]) {
                                ok = true;
                                cx[j][i] = 1;
                            }
                        }
                    }
                }else if(a[i] > 0) {
                    if(vm >= v[i]) {
                        long double x = (vm * vm - v[i] * v[i]) / 2.0 / a[i];
                        long double x1 = d[i] + x;
                        if(x1  >= l) continue;
                        for(int j = 1;j <= m;j++) {
                            if(x1 < p[j]) {
                                ok = true;
                                cx[j][i] = 1;
                            }
                        }
                    } else {
                        for(int j = 1;j <= m;j++) {
                            if(p[j] >= d[i]) {
                                ok = true;
                                cx[j][i] = 1;
                            }
                        }
                    }
                }else {
                    if(v[i] <= vm) continue;
                    long double x = (vm * vm - v[i] * v[i]) / 2.0 / a[i];
                    long double x1 = d[i] + x;
                    for(int j = 1;j <= m;j++) {
                        if(d[i] <= p[j] && p[j] < x1) {
                            ok = true;
                            cx[j][i] = 1;
                        }
                    }
                }
                if(ok == true) {
                    ansa++;
                }
            }
            int ans = 0, cel[30] = {};
            for(int i = 1;i <= m;i++){
                if(cel[i] == 1) continue;
                for(int j = 1;j <= m;j++) {
                    if(i == j || cel[j] == 1) continue;
                    if(cpr(i, j, n)) {
                        ans++;
                        cel[j] = 1;
                    }
                }
            }
            printf("%d %d\n", ansa, ans);
        }
    }
    return 0;
}

