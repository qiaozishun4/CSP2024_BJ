#include <bits/stdc++.h>
using namespace std;

/**

与加速度有关的定义和公式如下:
• 匀加速运动 是指物体在运动过程中,加速度保持不变的运动,即每单位时间内
速度的变化量是恒定的。
• 当一辆车的初速度为 v 0 、加速度 a ̸ = 0,做匀加速运动,则 t 时刻后它的速度
v 1 = v 0 + a × t,它的位移(即行驶路程)s = v 0 × t + 0.5 × a × t 2 。
• 当一辆车的初速度为 v 0 、加速度 a ̸ = 0,做匀加速运动,则当它的位移(即行驶
√
路程)为 s 时,这辆车的瞬时速度为 v 0 2 + 2 × a × s。
• 当一辆车的初速度为 v 0 、加速度 a ̸ = 0,在它的位移(即行驶路程)为
这辆车的瞬时速度为 v 1 。
如果你使用浮点数进行计算,需要注意潜在的精度问题。

**/

// a < 0 && vi < V no
// a < 0 && vi > V && when vi = V,

const int NR = 1e5 + 10;
const double eps = 1e-6;
int d[NR], a[NR], p[NR];

struct Node {
    double l, r;

    void clr() {
        l = r = 0;
    }
    bool operator < (const Node &o) const {
        return l < o.l;
    }
} s[NR];

struct Node2 {
    int l, r;

    void clr() {
        l = r = 0;
    }
    bool operator < (const Node2 &o) const {
        if (r != o.r) return r < o.r;
        return l < o.l;
    }
} s2[NR];

inline int read() {
    char c; int op, x;
    c = getchar();

    if (c == '-') op = -1, x = 0;
    else op = 1, x = c - '0';

    c = getchar();
    while (c != '\n' && c != ' ') {
        x = x * 10 + c - '0';
        c = getchar();
    }

    return op * x;
}

inline void print(int x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int t = read();
    while (t--) {
        memset(p, 0, sizeof(p));
        for (int i = 1; i < NR; i++)
            s[i].clr(), s2[i].clr();
        int n = read(), m = read(), L = read(), lim = read();
        for (int i = 1; i <= n; i++) {
            int v;
            d[i] = read(), v = read(), a[i] = read();
            if (a[i] == 0 && v <= lim) continue;
            if (a[i] == 0) {
                s[i].l = d[i], s[i].r = L;
                continue;
            }
            double dis = (1ll * lim * lim - v * v) / 2.0 / a[i] + d[i];
            if (d[i] - dis >= eps && a[i] < 0) continue;
            if (d[i] - dis >= eps) s[i].l = d[i], s[i].r = L;
            else if (L - dis >= eps) {
                if (a[i] < 0) s[i].l = d[i], s[i].r = dis;
                else s[i].l = dis, s[i].r = L;
            }
            else if (a[i] < 0) s[i].l = d[i], s[i].r = L;
        }

        int ans1 = 0, ans2 = 0;
        for (int i = 1; i <= m; i++)
            p[i] = read();
        sort(p + 1, p + m + 1);

        for (int i = 1; i <= n; i++) {
            if (abs(s[i].l) < eps && abs(s[i].r) < eps) continue;
            int k;

            if (s[i].l == d[i]) k = lower_bound(p + 1, p + m + 1, s[i].l) - p;
            else k = upper_bound(p + 1, p + m + 1, s[i].l) - p;

            if (k > m) continue;
            if (p[k] - s[i].r >= eps) continue;
            ans1++;

            int kk;
            if (s[i].r == L) kk = upper_bound(p + 1, p + m + 1, s[i].r) - p - 1;
            else kk = lower_bound(p + 1, p + m + 1, s[i].r) - p - 1;

            s2[ans1] = {k, kk};
        }

        sort(s2 + 1, s2 + ans1 + 1);
        for (int i = 1; i <= ans1; ) {
            ans2++;
            int t = s2[i].r;
            while (t >= s2[i].l && i <= ans1) i++;
        }

        print(ans1);
        printf(" ");
        print(m - ans2);
        print('\n');
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
