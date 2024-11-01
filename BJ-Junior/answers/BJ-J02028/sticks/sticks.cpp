#include<bits/stdc++.h>
using namespace std;
long long dp[10][100005][9];
long long cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long fast_pow(int a, int b){
    long long ans = 1;
    while(b){
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w", stdout);
    long long T;
    cin >> T;
    while(T--){
        memset(dp, 0x3f, sizeof(dp));
        long long n;
        cin >> n;
        for(int i = 0; i < 10; i++) dp[i][0][0] = 0;
        for(int k = 1; k <= 9; k++){
             for(int i = 0; i < 10; i++){
                for(int j = cnt[i]; j <= n; j++){
                    for(int l = 0; l <= 9; l++){
                        dp[i][j][k] = min(dp[i][j][k], dp[l][j - cnt[i]][k - 1] + i * fast_pow(10, k - 1));
                    }
                }
            }
        }
        long long minn = 0x3f3f3f3f3f3f3f3f;
        for(int i = 1; i <= 9; i++){
          for(int k = 1; k <= 9; k++){
            minn = min(minn, dp[i][n][k]);
          }
        }
        cout << (minn != 0x3f3f3f3f3f3f3f3f ? minn : -1) << '\n';
        //cout << dp[6][6][1];
    }
    return 0;
}
