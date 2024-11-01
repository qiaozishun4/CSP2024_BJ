#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long

using namespace std;

const int N = 2e5 + 10;

int T;
int n;
int a[N];
int k[N];
int ans = 0;

int r, b;

int calc () {
    r = -1, b = -1;
    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
         if (k[i] == 0) {
            if (r == -1) {
                r = a[i];
                continue;
            }
            else if (r == a[i]){
                res += a[i];
            }
            r = a[i];
         }
         else {
            if (b == -1) {
                b = a[i];
                continue;
            }
            else if (b == a[i]) {
                res += a[i];
            }
            b = a[i];
         }
    }

    return res;
}

void dfs (int x) {
    if (x == n + 1) {
        ans = max (ans, calc ());
        return ;
    }
    k[x] = 0;
    dfs (x + 1);
    k[x] = 1;
    dfs (x + 1);
}

signed main () {
    freopen ("color.in", "r", stdin);
    freopen ("color.out", "w", stdout);

    cin >> T;
    while (T -- ) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++ ) {
            cin >> a[i];
        }

        dfs (1);

        cout << ans << endl;
    }

    return 0;
}
