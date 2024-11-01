#include<bits/stdc++.h>
using namespace std;
#define int long long

int same[200005];
int n;
int num[200005];
int dp[200005][3][3];
int ton[1000005];

void sol(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> num[i];
    }
    if(n <= 15){
        int ma = 0;
        for(int i = 0;i < (1<<n);i++){
            int ans = 0;
            ton[0] = ton[1] = 0;
            for(int j = 1;j <= n;j++){
                bool x = i&(1<<(j-1));
                if(num[j] == num[ton[x]]){
                    ans += num[j];
                }
                ton[x] = j;
            }
            ma = max(ma,ans);
        }
        cout << ma << endl;
        return;
    }
    memset(dp,0,sizeof(dp));
    int ma = 0;
    for(int i = 2;i <= n;i++){
        dp[i][0][0] = max(dp[i-1][1][0],dp[i-1][0][0])+(num[i]==num[i-1])*num[i];
        dp[i][1][1] = max(dp[i-1][1][1],dp[i-1][0][1])+(num[i]==num[i-1])*num[i];
        int de = 0;
        for(int j = i-1;j >= 1;j--){
            dp[i][0][1] = max(dp[i][0][1],dp[j][1][0]+de+(num[i]==num[j-1])*num[i]);
            dp[i][1][0] = max(dp[i][1][0],dp[j][0][1]+de+(num[i] == num[j-1])*num[i]);
            de += (num[j] == num[j-1])*num[j];
        }
    }
    cout << max(max(dp[n][0][0],dp[n][0][1]),max(dp[n][1][0],dp[n][1][1])) << endl;
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int __;
    cin >> __;
    while(__--){
        sol();
    }
}
