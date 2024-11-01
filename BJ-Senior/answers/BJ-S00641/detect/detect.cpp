//BJ-S00641 detect.cpp
//No Data
//Writing
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const int INTINF = 2147483647;

int n, m, L, V;
int al, ar;

int p[100005];

struct Car {
    int d, v, a;
    int l, r;
    Car() : d(0), v(0), a(0), l(0), r(0) {}
    void read() {
        cin >> d >> v >> a;
        return;
    }
} c[100005];

bool IsEndRoad(int v0, int a, int id) {
    if (a > 0) return false;
    //printf("decide:%d<%d?%d\n", v0 * v0, -1 * p[id] * (2 * a), v0 * v0 < -1 * p[id] * (2 * a));
    return v0 * v0 < -1 * p[id] * (2 * a);
}
int GetNowSpeed(int v0, int a, int s) { //a=ans:(ans-1,ans]
    int l = 0, r = INTINF;
    while (l <= r - 2) {
        int mid = (l + r) >> 1;
        if ((1LL * mid * mid - v0 * v0) >= s * 2LL * a) r = mid;
        else l = mid;
    }
    return r;
}

bool cmp(int x, int id) {
    //printf("%d,%d(%d,%d,%d):", x, id, c[x].v, c[x].a, p[id] - c[x].d);
    if (p[id] < c[x].d || IsEndRoad(c[x].v, c[x].a, id)) {
        //printf("none\n");
        return false;
    }
    if (c[x].a == 0) return c[x].v > V;
    //printf("%d,%d(%d,%d,%d):", x, id, c[x].v, c[x].a, p[id] - c[x].d);
    //printf("%d\n", GetNowSpeed(c[x].v, c[x].a, p[id] - c[x].d));
    return GetNowSpeed(c[x].v, c[x].a, p[id] - c[x].d) > V;
}

void CalcLR(int x) {
    for (int j = 1; j <= m; j++) {
        if (cmp(x, j)) {
            c[x].l = j;
            break;
        }
    }
    if (c[x].l == 0) return;
    //printf("more...\n");
    for (int j = m; j >= 1; j--) {
        if (cmp(x, j)) {
            c[x].r = j;
            break;
        }
    }
    return;
}

bool scmp(Car x, Car y) {
    if (x.r != y.r) return x.r < y.r;
    return x.l < y.l;
}

int main() {
    //cout << GetNowSpeed(5, -2, 3) << endl;
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int TEST;
    cin >> TEST;
    while (TEST--) {
        cin >> n >> m >> L >> V;
        int ans1 = n, ans2 = 0, last = 0;
        for (int i = 1; i <= n; i++) c[i].read();
        for (int i = 1; i <= m; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) CalcLR(i);
        //for (int i = 1; i <= n; i++) cout << c[i].l << " " << c[i].r << endl;
        for (int i = 1; i <= n; i++) if (c[i].r == 0) ans1--;
        sort(c + 1, c + n + 1, scmp);
        for (int i = 1; i <= n; i++) {
            if (c[i].l > last) ans2++;
            last = c[i].r;
        }
        cout << ans1 << " " << n - ans2 << endl;
    }
    return 0;
}

