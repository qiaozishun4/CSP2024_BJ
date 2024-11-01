#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int n;
int v[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ans;
void dfs(int step, int res, int wei) {
    if(step == n) {
        ans = min(ans, res);
        return;
    }
    if(step > n) {
        return;
    }
    for(int j = 0; j <= 9; j++) {
        dfs(step + v[j], res + j * pow(10, wei - 1), wei);
    }
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T; cin >> T;
    while (T--) {
        int ans = 1e9;
        cin >> n;
        dfs(0, 0, 1);
        if(ans != 1e9) cout << ans << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
