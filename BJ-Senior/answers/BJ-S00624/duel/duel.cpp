#include <bits/stdc++.h>
using namespace std;

int r[100005];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, i, j;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> r[i];
    }
    sort(r + 1, r + n + 1);
    for (i = 2, j = 1; i <= n; i ++) {
        if (r[i] > r[j]) {
            j ++;
        }
    }
    cout << n - j + 1;
    return 0;
}

