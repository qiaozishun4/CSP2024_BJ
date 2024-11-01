#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
int cnt[N];

int main () {
    freopen ("duel.in", "r", stdin);
    freopen ("duel.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    sort (a + 1, a + n + 1);
    int r = 1;
    int ans = n;
    int val = 0;
    for (int i = 1; i <= n; i ++ ) {
        while (a[r] < a[i]) {
            r ++ ;
            val ++;
        }
        if (val) {
            val -- ;
            ans -- ;
        }
    }

    cout << ans << endl;

    return 0;
}
