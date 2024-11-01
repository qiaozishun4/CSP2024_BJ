#include <bits/stdc++.h>
using namespace std;
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, b[100];
int dp[100010]; // 用了x根火柴棍时数字的最短长度
string ans[100010];
bool cmp(char x, char y){
    return x < y;
}
string add(string s, char x){
    x += '0';
    string ns = x+s;
    int l = ns.size();
    sort(ns.begin(), ns.end(), cmp);
    if (ns[0] == '0') for (int i = 0; i < l; i++){
        if (ns[i] != '0'){
            ns[0] = ns[i];
            ns[i] = '0';
            break;
        }
    }
    return ns;
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T, n = 0;
    cin >> T;
    for (int i = 1; i <= T; i++){
        cin >> b[i];
        n = max(n, b[i]);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    ans[0] = "";
    for (int i = 2; i <= n; i++){
        for (int j = 0; j < 10; j++){
            if (i-a[j] < 0 || dp[i-a[j]] < 0) continue;
            if (i-a[j] == 0 && j == 0) continue;
            if (dp[i-a[j]]+1 < dp[i]){
                dp[i] = dp[i-a[j]]+1;
                ans[i] = add(ans[i-a[j]], j);
            }
            else if (dp[i-a[j]]+1 == dp[i]){
                string ns = add(ans[i-a[j]], j);
                if (ns < ans[i]) ans[i] = ns;
            }
        }
    }
    for (int i = 1; i <= T; i++){
        if (dp[b[i]] == 1061109567){
            cout << -1 << endl;
            continue;
        }
        cout << ans[b[i]] << endl;
    }
    return 0;
}
