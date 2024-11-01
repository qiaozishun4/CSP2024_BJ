// Zhang Yixun
// CSP-S T1 duel
// 100pts final

#include <bits/stdc++.h>
using namespace std;

int r[100005];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    sort(r+1, r+1+n);
    int j = 1;
    for (int i = 2; i <= n; i++) {
        if (r[i] > r[j]) {
            j++;
        }
    }
    cout << n - j + 1 << endl;
    return 0;
}