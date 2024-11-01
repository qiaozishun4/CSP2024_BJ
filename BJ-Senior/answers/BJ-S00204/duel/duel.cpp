#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    int ci[100005] = {};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ci[x--]++;
    }
    int maxd = 0;
    for (int i = 0; i < 100005; i++) {
        if (ci[i] > maxd) {
            maxd = ci[i];
        }
    }
    cout << maxd;
    return 0;
}
