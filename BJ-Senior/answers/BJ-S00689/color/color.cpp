#include<bits/stdc++.h>
using namespace std;
int a[1000010], l[1000010], dp[1000010], n, x, y, ans;
void dfs(int i, int s){
    if (i > n){
        ans = max(ans, s);
        return;
    }

    int ns = s;
    if (a[i] == x) ns += a[i];
    int tmp = x;
    x = a[i];
    dfs(i+1, ns);
    x = tmp;

    ns = s;
    if (a[i] == y) ns += a[i];
    tmp = y;
    y = a[i];
    dfs(i+1, ns);
    y = tmp;
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--){
        memset(dp, 0, sizeof(dp));
        memset(l, 0, sizeof(l));
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n <= 20){
            ans = 0;
            dfs(1, 0);
            cout << ans << endl;
            continue;
        }
        l[1] = 0;
        for (int i = 2; i <= n; i++){
            l[i] = i-1;
            for (int j = 1; j <= n; j++){
                if (i-j < 0) break;
                int x = i-j, y;
                y = dp[x];
                for (int k = x+2; k < i; k++){
                    if (a[k] == a[k-1]) y += a[k];
                }
                if (a[x+1] == a[l[x]]) y += a[x+1];
                if (a[i] == a[x]) y += a[i];
                if (y > dp[i]){
                    dp[i] = y;
                    if (x == i-1) l[i] = l[i-1];
                    l[i] = i-1;
                }
            }
            //cout << dp[i] << ' ';
        }
        cout << dp[n] << endl;
    }
    return 0;
}

