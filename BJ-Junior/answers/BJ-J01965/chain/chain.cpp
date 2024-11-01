#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

#define MY_TEST

void read(int &rtn) {
    char c = getchar();
    bool rev = false;
    rtn = 0;
    while (c < '0' || c > '9')
        rev |= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9')
        rtn = (rtn << 3) + (rtn << 1) + c - 48, c = getchar();
    if (rev) rtn = -rtn;
}

const int maxn = 100010, maxm = 200010, maxs = 200010, maxr = 110;

bool ans[maxr][maxs];
int n, m, L[maxn], pre[maxs], suf[maxs];
vector<int> S[maxn];
vector<bool> dp[maxn], dp_nxt[maxn];
// bool *dp[maxn], *dp_nxt[maxn];

int main() {
    #ifdef MY_TEST
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    #else
    freopen("chain6.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    #endif

    int T, q; read(T);
    while (T--) {
        memset(ans, 0, sizeof(ans));
        memset(L, 0, sizeof(L));
        // cin >> n >> m >> q;
        read(n), read(m), read(q);
        for (int i = 1; i <= n; ++i) {
            // cin >> L[i];
            read(L[i]);
            S[i].clear();
            S[i].resize(L[i] + 5);
            for (int j = 1; j <= L[i]; ++j)
                // cin >> S[i][j];
                read(S[i][j]);
        }
        for (int j = 0; j <= n + 1; ++j) {
            dp_nxt[j].clear(), dp_nxt[j].resize(L[j] + 5);
            // if (dp_nxt[j] != nullptr) free(dp_nxt[j]), dp_nxt[j] = nullptr;
            // dp_nxt[j] = (bool *) malloc(sizeof(bool) * (L[j] + 5));
        }
        for (int i = 1; i <= 100; ++i) {
            memset(pre, 0, sizeof(pre));
            for (int j = 1; j <= n; ++j) {
                dp[j] = dp_nxt[j];
                // if (dp[j] != nullptr) free(dp[j]), dp[j] = nullptr;
                // dp[j] = dp_nxt[j];
                // dp_nxt[j] = (bool *) malloc(sizeof(bool) * (L[j] + 5));
            }
            // memset(suf, 0, sizeof(suf));
            suf[1] = 0;
            if (i > 1)
                for (int j = n; j; --j) {
                    for (int k = L[j]; k; --k) {
                        suf[S[j][k]] += dp[j][k];
                    }
                }
            else suf[1] = 0x3f3f3f3f;
            for (int j = 1; j <= n; ++j) {
                for (int k = L[j]; k; --k) {
                    suf[S[j][k]] -= dp[j][k];
                }
                int in_que = 0;
                for (int k = 1; k <= L[j]; ++k) {
                    if (k > 1) {
                        if (k > m) in_que -= pre[S[j][k - m]] + suf[S[j][k - m]];
                        dp_nxt[j][k] = in_que;
                    }
                    in_que += pre[S[j][k]] + suf[S[j][k]];
                }
                for (int k = L[j]; k; --k) {
                    pre[S[j][k]] += dp[j][k];
                }
            }
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= L[j]; ++k) {
                    ans[i][S[j][k]] |= dp_nxt[j][k];
                }
            }
        }
        for (int i = 1, r, c; i <= q; ++i) {
            // cin >> r >> c;
            read(r), read(c);
            // cout << ans[r][c] << '\n';
            printf("%d\n", ans[r][c]);
        }
    }

    return 0;
}