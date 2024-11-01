#include <bits/stdc++.h>
using namespace std;
int n, r[100005];
bool vis[100005];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> r[i];
    sort(r + 1, r + n + 1);
    int last = 0, ans = 0;
    for(int i = 1;i <= n;i++) {
        last++;
        if(r[i] != r[i + 1] || i == n) {
            ans = max(0, ans - last);
            ans += last;
            last = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
