#include <bits/stdc++.h>
using namespace std;
int T, n, k, q, r, c;
vector<int> s[101000];
bool dfs(int leftr, int lastp, int lastc) {
    #ifdef Happy_David_3367_FLAG
        printf ("dfs (%d, %d, %d)\n", leftr, lastp, lastc);
    #endif
    if (!leftr) {
        if (lastc == c) {
            return true;
        } else {
            return false;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i != lastp) {
            #ifdef Happy_David_3367_FLAG
                printf ("dfs (%d, %d, %d) - Valid i: %d\n", leftr, lastp, lastc, i);
            #endif
            vector<int> p;
            for (int j = 0; j < s[i].size (); ++j) {
                if (s[i][j] == lastc) {
                    p.push_back (j);
                }
            }
            for (auto j : p) {
                for (int d = 2; d <= k; ++d) {
                    if (j + d < s[i].size ()) {
                        #ifdef Happy_David_3367_FLAG
                            printf ("dfs (%d, %d, %d) - Valid i: %d - Position: %d\n", leftr, lastp, lastc, i, j);
                        #endif
                        if (dfs (leftr - 1, i, s[i][j + d - 1])) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
void solve() {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d%d", &n, &k, &q);
        for (int i = 1; i <= n; ++i) {
            int l;
            scanf ("%d", &l);
            s[i].clear ();
            s[i].resize (l);
            for (int j = 0; j < l; ++j) {
                int m;
                scanf ("%d", &m);
                s[i][j] = m;
            }
        }
        for (int i = 1; i <= q; ++i) {
            scanf ("%d%d", &r, &c);
            printf ("%d\n", dfs (r, 0, 1));
        }
    }
}
int main() {
    #ifndef Happy_David_3367_FLAG
        freopen ("chain.in", "r", stdin);
        freopen ("chain.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
    #else
        freopen ("/home/cspj/BJ-J01428/chain/chain_test/chain1.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/chain/chain1.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
        freopen ("/home/cspj/BJ-J01428/chain/chain_test/chain2.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/chain/chain2.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
        freopen ("/home/cspj/BJ-J01428/chain/chain_test/chain3.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/chain/chain3.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
        freopen ("/home/cspj/BJ-J01428/chain/chain_test/chain4.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/chain/chain4.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
        freopen ("/home/cspj/BJ-J01428/chain/chain_test/chain5.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/chain/chain5.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
        freopen ("/home/cspj/BJ-J01428/chain/chain_test/chain6.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/chain/chain6.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
    #endif
    return 0;
}
// 实在调不出来了……也没有更好的思路的想法了，比赛只剩下15mins直接交上摆烂了。
