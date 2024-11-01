#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 9;
const int M = 1e6 + 9;
int n, T;
int loc[M], pre[N];
ll a[N], s[N], dp[N][2][2];
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = loc[a[i]];
        loc[a[i]] = i;
        s[i] = s[i-1];
        if(a[i]==a[i-1]) s[i] += a[i];
    }
    for(int i=1; i<=n; ++i){
        //dp[i][0] = dp[i-1][0] + (a[i]==a[i-1]) * a[i];
        //dp[i][1] = dp[i-1][1] + (a[i]==a[i-1]) * a[i];
        if(pre[i]) dp[i][0][1] = max(max(dp[pre[i]][0][0], dp[pre[i]][0][1]),
                      (pre[i]+1==i ? 0 : dp[pre[i]+1][1][1])) +
                      s[i] - s[pre[i]+1] + a[i];
        dp[i][0][0] = max(max(dp[i-1][0][0], dp[i-1][0][1]),
                          max(dp[i-1][1][0], dp[i-1][1][1]));
        //printf("dp %d :\nzu : %lld\nbu : %lld\n", i, dp[i][0][1], dp[i][0][0]);
        if(pre[i]) dp[i][1][1] = max(max(dp[pre[i]][1][0], dp[pre[i]][1][1]),
                      (pre[i]+1==i ? 0 : dp[pre[i]+1][0][1])) +
                      s[i] - s[pre[i]+1] + a[i];
        dp[i][1][0] = max(max(dp[i-1][1][0], dp[i-1][1][1]),
                          max(dp[i-1][0][0], dp[i-1][0][1])); 

        //printf("%lld %lld %lld %lld\n", dp[i][0][0], dp[i][0][1], dp[i][1][0], dp[i][1][1]);
    }
    cout << max(max(dp[n][0][0], dp[n][0][1]), max(dp[n][1][0], dp[n][1][1])) << '\n';
    for(int i=1; i<=n; ++i) loc[a[i]] = dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = 0;
    }
    return 0;
}