#include<bits/stdc++.h>
using namespace std;
int n; long long ans, sum = INT_MAX;
// 6 2 5 5 4 5 6 3 7 6
// 0 1 2 3 4 5 6 7 8 9
void dfs(int n, long long ans){
    if(n == 0){
       // cout << sum << ' ' << ans << ' ';
        sum = min(sum, ans);
     //   cout << '\n';
    }
    if(n < 2) return;
    if(n >= 6) {
         if(ans == 0) dfs(n - 6, ans * 10 + 6);
         else dfs(n - 6, ans * 10);
    }
    if(n >= 2) dfs(n - 2, ans * 10 + 1);
    if(n >= 5) dfs(n - 5, ans * 10 + 2);
    if(n >= 3) dfs(n - 3, ans * 10 + 7);
    if(n >= 7) dfs(n - 7, ans * 10 + 8);
}

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        cin >> n;
        if(n % 7 == 0){
            for(int i = 1; i <= n / 7; i++) cout << 8;
            continue;
        }
        ans = 0, sum = INT_MAX;
        dfs(n, ans);
        if(sum == INT_MAX) cout << -1 << '\n';
        else cout << sum << '\n';
    }
    return 0;
}
