#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int T, n, a[2005];
bool vis[2005];
void dfs(int step) {
    if(step == n + 1) {
        int num = 0, lastr = 0, lastb = 0;
        for(int i = 1;i <= n;i++) {
            if(vis[i]) {
                if(lastr != 0 && a[i] == a[lastr])
                   num += a[i];
                lastr = i;
            }
            else {
                if(lastb != 0 && a[i] == a[lastb])
                   num += a[i];
                lastb = i;
            }
        }
        ans = max(ans, num);
        return ;
    }
    vis[step] = true;
    dfs(step + 1);
    vis[step] = false;
    dfs(step + 1);
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1;i <= n;i++)
            cin >> a[i];
        ans = 0;
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}