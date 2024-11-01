#include <bits/stdc++.h>
using namespace std;

int r[100005];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int N, R, ans = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> R;
        r[R]++;
    }
    for (int i = 1; i <= 100000; i++) {
        ans -= min(ans, r[i]);
        ans += r[i];
    }
    cout << ans << endl;
    return 0;
}