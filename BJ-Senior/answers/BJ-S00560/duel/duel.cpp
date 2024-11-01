#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int p = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] > a[p]) p++;
    cout << n - p + 1 << "\n";
    return 0;
}

