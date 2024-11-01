

#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int T;
int N;
int M;
double L;
double V;
int d[100009];
double v[100009];
int a[100009];
int P[100009];
struct Seg {
    int l;
    int r;
    const bool operator < (const Seg &b) const {
        return r < b.r;
    }
} A[100009];
int cnt;
int res;

int Min (int a, int b) {
    return a < b ? a : b;
}

int Max (int a, int b) {
    return a > b ? a : b;
}

int main () {
    double ta;
    double da;
    int tp;
    int s;
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%lf%lf", &N, &M, &L, &V);
        for (int i = 1; i <= N; i++) scanf("%d%lf%d", &d[i], &v[i], &a[i]);
        for (int i = 1; i <= M; i++) scanf("%d", &P[i]);
        P[0] = -1e9;
        for (int i = 1; i <= N; i++) {
            if (!a[i]) {
                if (v[i] > V) A[i] = {lower_bound(P + 1, P + M + 1, d[i]) - P, M};
                else A[i] = {M + 1, M};
            }
            else {
                ta = a[i], da = d[i];
                if (a[i] > 0) {
                    tp = Max(da - 1, (V * V - v[i] * v[i]) / (2.0 * ta) + da);
                    A[i] = {upper_bound(P + 1, P + M + 1, tp) - P, M};
                }
                else {
                    if (v[i] > V) {
                        s = Min(ceil(da + v[i] * v[i] / (-2.0 * ta)), L + 1);
                        tp = Min(s, ceil((V * V - v[i] * v[i]) / (2.0 * ta) + da));
                        A[i] = {lower_bound(P + 1, P + M + 1, d[i]) - P, lower_bound(P + 1, P + M + 1, tp) - P - 1};
                    }
                    else A[i] = {M + 1, M};
                }
            }
        }
        sort(A + 1, A + N + 1);
        tp = cnt = res = 0;
        for (int i = 1; i <= N; i++) {
            if (A[i].l > A[i].r) continue;
            cnt++;
            if (A[i].l > tp) res++, tp = A[i].r;
        }
        printf("%d %d\n", cnt, M - res);
    }
    fclose(stdin), fclose(stdout);
    return 0;
}