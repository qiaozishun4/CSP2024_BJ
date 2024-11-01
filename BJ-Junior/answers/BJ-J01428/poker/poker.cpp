#include <bits/stdc++.h>
using namespace std;
const int N = 52 + 8;
int n;
set<pair<char, char>> c;
void solve() {
    n = 0;
    c.clear ();
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        char hs, ds;
        scanf ("\n%c%c", &hs, &ds);
        c.insert ({hs, ds});
    }
    printf ("%d\n", 52 - c.size ());
}
int main() {
    #ifndef Happy_David_3367_FLAG
        freopen ("poker.in", "r", stdin);
        freopen ("poker.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
    #else
        freopen ("/home/cspj/BJ-J01428/poker/poker_test/poker1.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/poker/poker1.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
        freopen ("/home/cspj/BJ-J01428/poker/poker_test/poker2.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/poker/poker2.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
        freopen ("/home/cspj/BJ-J01428/poker/poker_test/poker3.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/poker/poker3.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
    #endif
    return 0;
}
