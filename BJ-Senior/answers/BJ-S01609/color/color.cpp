#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MY_TEST

typedef long long ll;

int max(int &a, int &b) { return a > b ? a : b; }
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

const int maxn = 2010;

int n, A[maxn], dp[maxn][maxn];

int main() {
    #ifdef MY_TEST
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    #else
    freopen("color2.in", "r", stdin);
    freopen("color2.out", "w", stdout);
    #endif

    int T; read(T);
    while (T--) {
        memset(dp, 0, sizeof(dp));
        read(n);
        for (int i = 1; i <= n; ++i)
            read(A[i]);
        int mx = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                const int nxt = max(i, j) + 1;
                mx = max(mx, dp[i][j]);
                dp[nxt][j] = max(dp[i][j] + (A[nxt] == A[i] ? A[i] : 0), dp[nxt][j]);
                dp[i][nxt] = max(dp[i][j] + (A[nxt] == A[j] ? A[j] : 0), dp[i][nxt]);
            }
        }
        printf("%d\n", mx);
    }

    return 0;
}