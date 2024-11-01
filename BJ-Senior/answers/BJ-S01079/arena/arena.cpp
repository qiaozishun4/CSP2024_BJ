#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

long long T, n, m, K, R;
long long a[100001], c[100001];
long long x[4];
string s[21], S = "#";

long long v[4 * 131072 + 1];
long long dp[4 * 131072 + 1];
long long ans[100001];

void build(long long p) {
    if(p >= 2 * K) return;
    build(2 * p);
    build(2 * p + 1);
    if(dp[2 * p] + dp[2 * p + 1] == 0) dp[p] = p - K + 1;
    else dp[p] = dp[2 * p] + dp[2 * p + 1];
}

void update(long long p, long long r) {
    if(!p) return;
    if(p < K) {
        if(S[p] == '0') {
            if(v[2 * p] == -1) {
                v[p] = -1;
                dp[p] = dp[2 * p] + dp[2 * p + 1];
            } else if(v[2 * p] >= r) {
                v[p] = v[2 * p];
                dp[p] = dp[2 * p];
            } else {
                v[p] = v[2 * p + 1];
                dp[p] = dp[2 * p + 1];
            }
        } else {
            if(v[2 * p + 1] == -1) {
                v[p] = -1;
                dp[p] = dp[2 * p] + dp[2 * p + 1];
            } else if(v[2 * p + 1] >= r) {
                v[p] = v[2 * p + 1];
                dp[p] = dp[2 * p + 1];
            } else {
                v[p] = v[2 * p];
                dp[p] = dp[2 * p];
            }
        }
    }
    update(p / 2, r + 1);
}

long long add(long long p, long long val) {
    v[K + p - 1] = val;
    update(K + p - 1, 0);
    long long t = K;
    p--;
    while(p >= 1) {
        t /= 2;
        p /= 2;
    }
    return dp[t];
}

int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(long long i = 1;i <= n;i++) scanf("%lld", &a[i]);
    for(long long i = 1;i <= m;i++) scanf("%lld", &c[i]);
    K = R = 1;
    while(K < n) {
        cin >> s[R];
        R++;
        K *= 2;
    }
    --R;
    for(long long i = R;i;i--) S += s[i];
    scanf("%lld", &T);
    for(long long i = 1;i <= T;i++) {
        memset(v, -1, sizeof(v));
        memset(dp, 0, sizeof(dp));
        build(1);
        for(long long j = 0;j < 4;j++) scanf("%lld", &x[j]);
        for(long long j = 1;j <= n;j++) {
            ans[j] = add(j, a[j] ^ x[j & 3LL]);
        }
        long long A = 0;
        for(long long j = 1;j <= m;j++) {
            A = A ^ (j * ans[c[j]]);
        }
        printf("%lld\n", A);
    }
    return 0;
}
