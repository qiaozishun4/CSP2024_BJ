#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MY_TEST

typedef long long ll;

void read(int &rtn) {
    bool rev = false;
    char c = getchar();
    rtn = 0;
    while (c < '0' || c > '9')
        rev |= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9')
        rtn = (rtn << 3) + (rtn << 1) + c - 48, c = getchar();
    if (rev) rtn = -rtn;
}
void read(ll &rtn) {
    bool rev = false;
    char c = getchar();
    rtn = 0LL;
    while (c < '0' || c > '9')
        rev |= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9')
        rtn = (rtn << 3) + (rtn << 1) + c - 48, c = getchar();
    if (rev) rtn = -rtn;
}
void read(char &rtn) {
    do rtn = getchar();
    while (rtn != '0' && rtn != '1');
}

const int maxn = 100010, mlg = 18;
int lg2[maxn];

int n, q, K, A[maxn], C[maxn], D[mlg][maxn], st[mlg][maxn];

ll sumInd(int l, int r) {
    return ll(l + r) * (r - l + 1) >> 1;
}

void initSt() {
    for (int i = 1; i <= n; ++i)
        st[0][i] = i;
    for (int k = 1; k <= K; ++k) {
        int cnt = 0;
        for (int i = 1; i + (1 << k) - 1 <= n; i += (1 << k)) {
            ++cnt;
            if (!D[k][cnt]) st[k][i] = (A[st[k - 1][i]] >= k ? st[k - 1][i] : st[k - 1][i + (1 << k - 1)]);
            else st[k][i] = (A[st[k - 1][i + (1 << k - 1)]] >= k ? st[k - 1][i + (1 << k - 1)] : st[k - 1][i]);
        }
    }
}

int main() {
    #ifdef MY_TEST
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    #else
    freopen("arena2.in", "r", stdin);
    // freopen("arena2.out", "w", stdout);
    #endif

    for(int x = 0b10; x < maxn; x <<= 1)
        lg2[x] = lg2[x >> 1] + 1;

    read(n), read(q);
    for (int i = 1; i <= n; ++i)
        read(A[i]);
    for (int i = 1; i <= q; ++i)
        read(C[i]);
    for (K = 0; (1 << K) < n; ++K);
    char c;
    for (int i = 1; i <= K; ++i)
        for (int j = 1; j <= (1 << (K - i)); ++j)
            read(c), D[i][j] = (c == '1');
    int T, x[4]; read(T);
    while (T--) {
        read(x[0]), read(x[1]), read(x[2]), read(x[3]);
        for (int i = 1; i <= n; ++i)
            A[i] ^= x[i % 4];
        initSt();
        ll ans = 0LL;
        for (int i = 1; i <= q; ++i) {
            const int lgC = lg2[C[i]];
            if ((1 << lgC) == C[i]) {
                ans ^= (ll)i * st[lgC][1];
                continue;
            }
            // ll cont = 0LL;
            // for (int j = 1, k = lgC, cur = 0; j <= C[i] && ~k; j += (1 << k--), cur = cur + 1 << 1) {
            //     while (j + (1 << k) - 1 > C[i]) --k, cur <<= 1;
            //     if (!D[k][cur + 1]) {
            //         if (A[st[k][j]] >= k) {
            //             cont += st[k][j];
            //             break;
            //         } else {
            //             if (j + (1 << k) - 1 == C[i]) {
            //                 cont += sumInd(C[i] + 1, j + (1 << k + 1) - 1);
            //                 break;
            //             }
            //         }
            //     } else {
            //         if (j + (1 << k) - 1 == C[i]) {
            //             break;
            //         }
            //     }
            // }
            // ans ^= (ll)i * cont;
        }
        printf("%lld\n", ans);
    }

    return 0;
}