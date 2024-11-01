// By Pr_159
// Sugar_Pigeon & 159 rp++!
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 2e5 + 5;

int T, n, a[N];
bool vis[N];
LL ans = INT_MIN;

void dfs(int step) {
    if(step == n) {
        LL sum = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = i - 1; j >= 1; --j) {
                if(vis[i] == vis[j]) {
                    if(a[i] == a[j]) {
                        sum += a[i];
                    }
                }
            }
        }
        ans = max(ans, sum);
        return;
    }
    vis[step] = 1;
    dfs(step + 1);
    vis[step] = 0;
    dfs(step + 1);
    return;
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            vis[i] = 0;
        }
        ans = INT_MIN;
        if(n <= 15) {
            dfs(1);
            cout << ans << '\n';
        }
    }
    return 0;
}
