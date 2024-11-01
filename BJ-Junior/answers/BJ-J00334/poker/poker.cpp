#include <bits/stdc++.h>
using namespace std;

int cnt[200][200];

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n; cin >> n;
    int ans = 52;
    for (int i = 1; i <= n; i++) {
        char a, b;
        cin >> a >> b;
        if (cnt[a - '0'][b - '0']) continue;
        else {
            cnt[a - '0'][b - '0']++;
            ans--;
        }
    }
    cout << ans;
    return 0;
}
