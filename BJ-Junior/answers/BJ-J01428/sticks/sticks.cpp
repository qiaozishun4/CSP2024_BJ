#include <bits/stdc++.h>
using namespace std;
void solve() {
    int need[101000], ans[101000];
    memset (ans, 255, sizeof (ans));
    for (int i = 1; i <= 100000; ++i) {
        int j = i, res = 0;
        while (j) {
            int k = j % 10;
            switch (k) {
                case 0:
                    res += 6;
                    break;
                case 1:
                    res += 2;
                    break;
                case 2:
                    res += 5;
                    break;
                case 3:
                    res += 5;
                    break;
                case 4:
                    res += 4;
                    break;
                case 5:
                    res += 5;
                    break;
                case 6:
                    res += 6;
                    break;
                case 7:
                    res += 3;
                    break;
                case 8:
                    res += 7;
                    break;
                case 9:
                    res += 6;
                    break;
            }
            j /= 10;
        }
        need[i] = res;
        if (ans[res] == -1) {
            ans[res] = i;
        }
    }
    int T;
    scanf ("%d", &T);
    while (T--) {
        int n;
        scanf ("%d", &n);
        printf ("%d\n", ans[n]);
    }
}
int main() {
    #ifndef Happy_David_3367_FLAG
        freopen ("sticks.in", "r", stdin);
        freopen ("sticks.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
    #else
        freopen ("/home/cspj/BJ-J01428/sticks/sticks_test/sticks1.in", "r", stdin);
        freopen ("/home/cspj/BJ-J01428/sticks/sticks1.out", "w", stdout);
        solve ();
        fclose (stdin);
        fclose (stdout);
    #endif
    return 0;
}
