#include <bits/stdc++.h>
using namespace std;
int n, a[200005], c[200005], ans = 0;
void dfs(int x){
    if(x > n){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i-1; j >= 1; j--){
                if(c[i] == c[j]){
                    if(a[i] == a[j]) cnt += a[i];
                    break;
                }
            }
        }
        ans = max(ans, cnt);
        return;
    }
    c[x] = 0;
    dfs(x + 1);
    c[x] = 1;
    dfs(x + 1);
    c[x] = 0;
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        ans = 0;
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}
