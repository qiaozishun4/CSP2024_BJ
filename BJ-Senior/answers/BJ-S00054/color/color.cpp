#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 200005;
int a[MAXN], n, ans;
int dp[MAXN];
int f[5][MAXN];
int color[MAXN];
void solve();
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        memset(f, 0, sizeof f);
        solve();
    }
}

void solve(){
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++){
            int j;
        for(j = i-1; j >= 0; j --)
            if(a[i] == a[j])
                break;
        if(j < 1){
            continue;
        }
        if(!color[j])
            color[j] = color[i] = 1;
        color[i] = color[j];
        int ano, now = color[i];
        if(color[i] == 1)
            ano = 2;
        else
            ano = 1;
        f[now][i] = f[now][j-1] + a[i];
        f[ano][i] = f[ano][i-1];

        ans = max(ans, f[now][i]+f[ano][i]);
    }
    cout << ans << '\n';
}
