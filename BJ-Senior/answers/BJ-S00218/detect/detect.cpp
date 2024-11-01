#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#define ld long double
#define zqy pair<int, int>
using namespace std;
const int N = 1e5 + 5;
const int L = 1e6 + 5;
const ld eps = 1e-9;
int T;
int n, m, l, v;
struct car {
    int d, v, a;
} b[N];
zqy pr[N];
bool cmp(zqy p1, zqy p2) {
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}
int c[L];
int nxt[L];
int lst[L];
int read() {
    int f = 1;
    int w = 0;
    char ch = '#';
    while((ch > '9' || ch < '0') && ch != '-') ch = getchar();
    if(ch == '-') f = -1, ch = getchar();
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return f * w;
}
int sl = 0;
ld sol[3];
void solve(ld a, ld b, ld c) {
    ld d = b * b - 4 * a * c;
    if(d > -eps && d < eps) d = 0;
    sl = 0;
    if(d < 0) return;
    if(d == 0) {
        sol[++sl] = -b / 2 / a;
        return;
    }
    d = sqrtl(d);
    sol[++sl] = (-b + d) / 2 / a;
    sol[++sl] = (-b - d) / 2 / a;
    if(sol[2] < sol[1]) swap(sol[2], sol[1]);
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    T = read();
    for(int ti = 1; ti <= T; ti++) {
        n = read(), m = read(), l = read(), v = read();
        int cnt = 0;
        for(int i = 1; i <= n; i++) b[i].d = read(), b[i].v = read(), b[i].a = read();
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= m; i++) c[read()] = i;
        for(int i = 0; i <= l; i++) {
            if(c[i]) lst[i] = c[i];
            else lst[i] = (i == 0) ? 0 : lst[i - 1];
        }
        for(int i = l; i >= 0; i--) {
            if(c[i]) nxt[i] = c[i];
            else nxt[i] = (i == l) ? 0 : nxt[i + 1];
        }
        for(int i = 1; i <= n; i++) {
            if(b[i].a == 0) {
                if(b[i].v > v && nxt[b[i].d] > 0) pr[++cnt] = (zqy){nxt[b[i].d], m};
            } else {
                solve(b[i].a / 2.0, b[i].v, -l + b[i].d);
                ld t = 1e4 + 5;
                for(int i = 1; i <= sl; i++) {
                       if(sol[i] > 0) t = min(t, sol[i]);
                }
                if(t > 1e4) t = (ld)b[i].v / -b[i].a;
                if(b[i].a > 0) {
                    if(b[i].v > v) {
                        if(nxt[b[i].d] > 0) pr[++cnt] = (zqy){nxt[b[i].d], m};
                    } else {
                        ld t1 = (ld)(v - b[i].v) / b[i].a;
                        if(t1 < t) {
                            int lf = (int)(b[i].d + (ld)1.0 * b[i].v * t1 + (ld)0.5 * b[i].a * t1 * t1) + 1;
                            lf = nxt[lf];
                            if(lf > 0) pr[++cnt] = (zqy){lf, m};
                        }
                    }
                } else {
                    if(b[i].v > v) {
                        ld t1 = (ld)(v - b[i].v) / b[i].a;
                        if(t1 > t + eps) {
                            if(nxt[b[i].d] > 0) pr[++cnt] = (zqy){nxt[b[i].d], m};
                        } else {
                            int rt = ceil(b[i].d + (ld)1.0 * b[i].v * t1 + (ld)0.5 * b[i].a * t1 * t1) - 1;
                            if(rt >= 0 && lst[rt] > 0 && nxt[b[i].d] <= lst[rt]) pr[++cnt] = (zqy){nxt[b[i].d], lst[rt]};
                        }
                    }
                }
            }
        }
        if(cnt == 0) printf("0 %d\n", m);
        else {
            sort(pr + 1, pr + cnt + 1, cmp);
            int lst = 0;
            int ans = 0;
            for(int i = 1; i <= cnt; i++) {
                if(lst >= pr[i].first) continue;
                ans++;
                lst = pr[i].second;
            }
            printf("%d %d\n", cnt, m - ans);
        }
    }
    return 0;
}
