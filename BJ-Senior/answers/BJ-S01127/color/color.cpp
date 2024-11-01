#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long dp[200005],sumv[200005],maxn[1000005],maxn2;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >> t;
//15 5 3 7 2 4 13 11 6 5 5 3 5 12 8 13
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            sumv[i] = sumv[i - 1] + (a[i] == a[i - 1]) * a[i];
        }
        for(int i = 1;i <= n + 1;i++){
            //for(int j = 0;j < i - 1;j++){
            //    dp[i] = max(dp[i],dp[j + 1] - sumv[j + 1] + (a[i] == a[j]) * a[i] + sumv[i - 1]);
            //}
            dp[i] = max(maxn[a[i]],maxn2) + sumv[i - 1];
            //cerr << dp[i] << " ";
            maxn[a[i - 1]] = max(maxn[a[i - 1]],dp[i] - sumv[i] + a[i - 1]);
            maxn2 = max(maxn2,dp[i] - sumv[i]);
        }
        cout << dp[n + 1] << '\n';
        for(int i = 1;i <= n + 1;i++){
            dp[i] = 0;
            maxn[a[i]] = 0;
        }
        maxn2 = 0;
    }
    return 0;
}
/*
dp[i]:第i位染成蓝,i-1位为红最大得分
dp[i] = max(dp[j + 1] + sumv[i - 1] - sumv[j + 1] + (a[i] == a[j]) * a[i])

maxn[i]:max(dp[j + 1] - sumv[j + 1] + a[j])(数字为i时的)
maxn2:(dp[j + 1] - sumv[j + 1])
dp[i] = max(maxn[a[i]],maxn2) + sumv[i - 1]
*/
