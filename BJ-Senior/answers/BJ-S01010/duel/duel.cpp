#include <bits/stdc++.h>
using namespace std;

int n, v[100010];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    int l = 1, r = 2, ans = n;
    while (l <= n && r <= n) {
        if (v[r] > v[l]) {
            ans--, l++;
        }
        r++;
    }
    cout << ans;
    return 0;
}
