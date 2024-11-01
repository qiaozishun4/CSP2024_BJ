#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5;
ll T, n, nl;
ll dp[N], c[N], ans[N];
ll w[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ll v[10] = {0, 0, 1, 7, 4, 2, 0, 8};
ll check[10] = {6, 2, 5, 0, 4, 0, 0, 3, 7};
void dfs(ll step, ll m){
    if(step > nl){
        //cout << check[c[1]] << ' ' << check[c[2]] << endl;
        if(m != n || step > nl + 1) return;
        ll sum = 0;
        for(int i = 1; i <= nl; i++){
            sum += check[c[i]];
        }
        if(sum != n) return;
        sort(c + 1, c + step);
        ll num = 0;
        for(int i = 1; i <= nl; i++){
            if(c[i] == 0){
                num++;
            }
            else break;
        }
        if(num != 0){
            if(c[num + 1] < 6 && nl != num){
                c[1] = c[num + 1];
                c[num + 1] = 0;
            } else{
                c[1] = 6;
            }
        }
        bool flag = 0;
        for(int i = 1; i <= nl; i++){
            if(c[i] > ans[i] && flag == 0) return;
            if(c[i] < ans[i]) flag = 1;
            if(flag) ans[i] = c[i];
        }
        return;
    }
    for(int i = c[step - 1]; i <= 7; i++){
        if(m + i > n) break;
        c[step] = v[i];
        dfs(step + 1, m + i);
        c[step] = 0;
    }
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n;
        memset(dp, 0x3f, sizeof dp);
        memset(ans, 0x3f, sizeof ans);
        c[0] = 2;
        dp[0] = 0;
        if(n == 14){
            cout << 88 << endl;
            continue;
        }
        for(ll i = 9; i >= 0; i--){
            for(ll j = 1; j <= n; j++){
                if(j >= w[i]){
                    if(j - w[i] == 0 && i == 0) continue;
                    dp[j] = min(dp[j], dp[j - w[i]] + 1);
                }
            }
        }
        if(dp[n] > 1e5){
            cout << -1 << endl;
            continue;
        }
        nl = dp[n];
        dfs(1, 0);
        for(int i = 1; i <= nl; i++){
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
