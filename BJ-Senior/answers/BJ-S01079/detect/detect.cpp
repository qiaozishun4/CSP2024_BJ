#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int read() {
    bool nega = false;
    int res = 0;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') nega = true;
        ch = getchar();
    }
    while(isdigit(ch)) {
        res = res * 10 + (ch - '0');
        ch = getchar();
    }
    if(nega) res = -res;
    return res;
}

int T, n, m, L, V;
int d[100001], v[100001], a[100001];
int p[100001];

struct Segment {
    int l, r; //[l, r)

    Segment(int x = 0, int y = 0) {
        l = x;
        r = y;
    }

    friend bool operator < (Segment A, Segment B) {
        return A.r < B.r || (A.r == B.r && A.l < B.l);
    }
} S[100001];

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    double t, s;
    int cnt;
    while(T--) {
        memset(S, 0, sizeof(S));
        cnt = 0;/*
        scanf("%d%d%d%d", &n, &m, &L, &V);
        for(int i = 1;i <= n;i++) scanf("%d%d%d", &d[i], &v[i], &a[i]);
        for(int i = 1;i <= m;i++) scanf("%d", &p[i]);*/
        n = read(); m = read(); L = read(); V = read();
        for(int i = 1;i <= n;i++) {
            d[i] = read();
            v[i] = read();
            a[i] = read();
        }
        for(int i = 1;i <= m;i++) p[i] = read();
        for(int i = 1, x, y;i <= n;i++) {
            x = lower_bound(p + 1, p + m + 1, d[i]) - p;
            y = m + 1;
            if(a[i] == 0) {
                if(v[i] > V && d[i] <= p[m]) cnt++;
                else x = y = 0;
            } else if(a[i] > 0) {
                if(v[i] > V) {
                    if(d[i] <= p[m]) cnt++;
                    else x = y = 0;
                } else {
                    t = double(V - v[i]) / double(a[i]);
                    s = double(d[i]) + (double)v[i] * t + 0.5D * (double)a[i] * (t * t);
                    x = lower_bound(p + 1, p + m + 1, floor(s) + 1) - p;
                    if(x <= m) cnt++;
                    else x = y = 0;
                }
            } else {
                if(v[i] > V) {
                    t = double(V - v[i]) / double(a[i]);
                    s = double(d[i]) + (double)v[i] * t + 0.5D * (double)a[i] * (t * t);
                    y = upper_bound(p + 1, p + m + 1, floor(s)) - p;
                    if(y > x) cnt++;
                    else x = y = 0;
                }
            }
            S[i] = Segment(x, y);
        }
        printf("%d ", cnt);
        cnt = 0;
        sort(S + 1, S + n + 1);
        for(int i = 1, l = 0;i <= n;i++) {
            if(l >= S[i].l || S[i].l == S[i].r) continue;
            l = S[i].r - 1;
            cnt++;
        }
        printf("%d\n", m - cnt);
    }
    return 0;
}
