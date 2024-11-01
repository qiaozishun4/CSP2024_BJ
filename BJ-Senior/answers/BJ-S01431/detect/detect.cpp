#include <cstdio>
#include <algorithm>
using namespace std;

inline void read(int &x) {
    x = 0;
    register int w = 1;
    register char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') w = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
    x *= w;
}

const int N = 1e5 + 5;
int t;
int n, m, l, v;
int p[N];
struct Node {
    int d, v, a;
    int l, r;
} car[N];

int getv(int v0, int a, int s) {
    return v0 * v0 + 2 * a * s;
}
int gets(int v0, int a) { // dont / 2a
    return v * v - v0 * v0 / (2 * a);
}
bool cmp3(Node a, Node b) {
    return a.l < b.l;
}

void solve1() {
    int ans = 0;
    for (int i = 1; i <= n; i++) 
        if (car[i].d <= p[m] && car[i].v > v) ans++;
    printf("%d ", ans);
    if (ans) printf("%d\n", m - 1);
    else printf("%d\n", m);
}
void solve2() {
    int ans = 0;
    for (int i = 1; i <= n; i++) 
        if (car[i].d <= p[m] && getv(car[i].v, car[i].a, p[m] - car[i].d) > v * v) ans++;
    printf("%d ", ans);
    if (ans) printf("%d\n", m - 1);
    else printf("%d\n", m);
}
void solve3() {
    for (int i = 1; i <= n; i++) {
        if (car[i].v < v) {
            car[i].l = -1;
            continue;
        } 
        car[i].l = car[i].d;
        car[i].r = gets(car[i].v, car[i].a);
    }
    sort(car + 1, car + n + 1, cmp3);
    int now = 1, ans = 0, las = 0;
    while (now <= n && car[now].l == -1) now++;
    while (now <= n) {
        int pos = upper_bound(p + 1, p + m + 1, car[now].r) - p;
        if (car[now].l <= p[pos] && car[now].r <= p[pos]) {
            ans++; las++; now++;
            while (now <= n && p[pos] >= car[now].l) {
                now++;
                if (p[pos] <= car[now].r) ans++;
            }
        } else now++;
    }
    printf("%d %d\n", ans, las);
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    read(t);
    while (t--) {
        read(n); read(m); read(l); read(v);
        bool ta, tb, tc; ta = tb = tc = true;
        for (int i = 1; i <= n; i++) {
            read(car[i].d); read(car[i].v); read(car[i].a);
            if (car[i].a != 0) ta = false;
            else if (car[i].a < 0) tb = false;
            else tc = false;
        }
        for (int i = 1; i <= m; i++) read(p[i]);
        if (ta) solve1();
        else if (tb) solve2();
        else if (tc) solve3();
    }
    return 0;
}