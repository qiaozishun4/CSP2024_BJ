#include <bits/stdc++.h>
using namespace std;
void solve() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        int n, m, k;
        scanf ("\n%d %d %d", &n, &m, &k);
        int x, y, d;
        scanf ("\n%d %d %d", &x, &y, &d);
        char mp[1010][1010];
        for (int i = 1; i <= n; ++i) {
            scanf ("\n");
            for (int j = 1; j <= m; ++j) {
                scanf ("%c", &mp[i][j]);
            }
        }
        set<pair<int, int>> vis;
        vis.insert (make_pair (x, y));
        while (k--) {
            int nx = x, ny = y;
            switch (d) {
                case 0:
                    ++ny;
                    break;
                case 1:
                    ++nx;
                    break;
                case 2:
                    --ny;
                    break;
                case 3:
                    --nx;
                    break;
            }
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && mp[nx][ny] == '.') {
                x = nx;
                y = ny;
            } else {
                d = (d + 1) % 4;
            }
            vis.insert (make_pair (x, y));
        }
        printf ("%d\n", vis.size ());
    }
}
int main() {
    #ifndef Happy_David_3367_FLAG
        freopen ("explore.in", "r", stdin);
        freopen ("explore.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
    #else
        freopen ("/home/cspj/BJ-J01428/explore/explore_test/explore1.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/explore/explore1.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
        freopen ("/home/cspj/BJ-J01428/explore/explore_test/explore2.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/explore/explore2.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
        freopen ("/home/cspj/BJ-J01428/explore/explore_test/explore3.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/explore/explore3.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
        freopen ("/home/cspj/BJ-J01428/explore/explore_test/explore4.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/explore/explore4.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
        freopen ("/home/cspj/BJ-J01428/explore/explore_test/explore5.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/explore/explore5.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
    #endif
    return 0;
}
