#include <bits/stdc++.h>
using namespace std;
int n, a[25], col[25];
// red : 0
// blue : 1
void solve(){
    cin >> n;
    int ans = -2e9;
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < (1 << n);i++){
        for (int j = 0;j < n;j++) col[j] = bool(i & (1 << j));
        int sum = 0;
        for (int j = 1;j < n;j++){
            int k = j - 1;
            while (k >= 0 && col[j] != col[k]) k--;
            if (k >= 0 && a[j] == a[k]) sum += a[j];
        } ans = max(ans, sum);
    } cout << ans << endl;
} int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
