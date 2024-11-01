#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 105;
int n, k, q, l[N];
vector <int> a[N];
vector <bool> dp[M][N];
int is[M][N];
void setup(int x) {
    memset(l, 0, sizeof(l));
    memset(is, 0, sizeof(is));
    for (int i = 1; i <= x; i++) {
        a[i].clear();
    }
    for (int i = 0; i <= 100; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j].clear();
        }
    }
}
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> k >> q;
        setup(n);
        for (int i = 1; i <= n; i++) {
            cin >> l[i];
            for (int j = 1; j <= l[i]; j++) {
                int x; cin >> x;
                a[i].push_back(x);
                if (x == 1) {
                    dp[0][i].push_back(1);
                    is[0][1]++;
                } else dp[0][i].push_back(0);
            }
        }
        for (int i = 1; i <= 100; i++) {
            for (int j = 1; j <= n; j++) {
                int ncnt = 0;
                for (int kk = 0; kk < l[j]; kk++) {
                    int nis1, nis2;
                    if (kk - 1 >= 0) nis1 = is[i - 1][a[j][kk - 1]] - int(dp[i - 1][j][kk - 1]);
                    if (kk - 1 >= 0 && nis1 > 0) ncnt++;
                    if (kk - k >= 0) nis2 = is[i - 1][a[j][kk - k]] - int(dp[i - 1][j][kk - k]);
                    if (kk - k >= 0 && nis2 > 0) ncnt--;
                    if (ncnt > 0) {
                        dp[i][j].push_back(1);
                        is[i][a[j][kk]]++;
                    } else dp[i][j].push_back(0);
                }
            }
        }
        while (q--) {
            int rr, cc;
            cin >> rr >> cc;
            cout << (is[rr][cc] > 0 ? 1 : 0) << '\n';
        }
    }
    return 0;
}
