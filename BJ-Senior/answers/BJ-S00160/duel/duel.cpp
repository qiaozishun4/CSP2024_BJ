#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, maxn = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    for (int i = 1; i <= n; i++) if (b[a[i]] > maxn) maxn = b[a[i]];
    cout << maxn;
    return 0;
}