

#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

const int MAXI = 1e5 + 9;
int n, a[MAXI];

signed main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > a[cnt + 1]) cnt++;

    cout << n - cnt << '\n';

    return 0;
}
