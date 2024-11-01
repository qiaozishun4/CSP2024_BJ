

#include <cstdio>
#include <cstring>
#define ll long long

using namespace std;

int T;
int N;
ll A[200009];
ll S[200009];
ll f[200009];
ll mxf[1000009];
ll res;

ll Max (ll a, ll b) {
    return a > b ? a : b;
}

int main () {
    ll smxf;
    ll smxg;
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &T);
    memset(mxf, 0xf1, sizeof(mxf));
    while (T--) {
        for (int i = 1; i <= N; i++) mxf[A[i]] = -1e18;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
        S[N + 1] = 0;
        for (int i = 2; i <= N; i++) S[i] = S[i - 1] + (ll)(A[i] * (A[i] == A[i - 1]));
        smxf = 0;
        for (int i = 1; i <= N; i++) {
            f[i] = Max(smxf + S[i - 1], mxf[A[i]] + S[i - 1] + A[i]);
            smxf = Max(smxf, f[i] - S[i]);
            if (i) mxf[A[i - 1]] = Max(mxf[A[i - 1]], f[i] - S[i]);
        }
        res = 0;
        for (int i = 1; i <= N; i++) res = Max(res, f[i] + S[N] - S[i]);
        printf("%lld\n", res);
    }
    fclose(stdin), fclose(stdout);
    return 0;
}