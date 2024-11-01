

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, t) for(int i = s; i <= t; i++) 
#define per(i, s, t) for(int i = t; i >= s; i--)

typedef long long ll;
typedef long double ldb;

const int MAXN = 1e5 + 9;

int n, m;
int a1[MAXN];
int a[MAXN];
int la[MAXN];
int c[MAXN];
bool d[19][(1 << 18)];
int lwin = 0;
int res[19];

void Dfs1 (int *cur, int l, int step) {

    int nxt[l];

    if (l == 1) {
        lwin = cur[1];
        return;
    }

    rep (i, 1, l / 2) {
        if (d[step][i]) { // cur[i * 2] vs cur[i * 2 - 1]
            if (a[cur[i * 2]] >= step) {
                nxt[i] = cur[i * 2];
            }

            else {
                nxt[i] = cur[i * 2 - 1];
            }
        }

        else { // cur[i * 2 - 1] vs cur[i * 2]
            if (a[cur[i * 2 - 1]] >= step) {
                nxt[i] = cur[i * 2 - 1];
            }

            else {
                nxt[i] = cur[i * 2];
            }
        }
    }

    Dfs1(nxt, l / 2, step + 1);

}

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);

    cin >> n >> m;

    rep (i, 1, n) {
        cin >> a1[i];
    }

    rep (j, 1, m) {
        cin >> c[j];
    }

    int K = log2(n + 1);
    vector<int> rwin[K];

    rep (i, 1, K) {
        rep (j, 1, (1 << (K - i + 1))) {
            char c;
            cin >> c;
            d[i][j] = c - '0';
        }
    }

    int T;

    cin >> T;

    rep (i, 1, T) {
        int x[4];
        int ans = 0;

        cin >> x[0] >> x[1] >> x[2] >> x[3];

        rep (j, 1, n) {
            a[j] = a1[j] ^ x[j % 4];
        }
        
        for (int j = 1; j <= n; j *= 2) {
            rep (k, j / 2, j) {
                la[k] = k;
            }

            Dfs1(la, j, 1);
            res[(int) log2(j)] = lwin;
        }

        rep (j, 1, m) {
            int Kk = log2(c[j] + 1);

            if ((1 << Kk) == c[j]) {
                ans ^= (res[Kk] * j);
            }
            
            
            /*
            else {
                rep (k, 1, (1 << (Kk - 1))) {
                    la[k] = k;
                }

                Dfs1(la, (1 << (Kk - 1)), 1);


            }
             */
        }
        
        cout << ans << '\n';
    }

    return 0;

}