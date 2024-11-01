#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int T;
int n;
int a[N];
int dp[N][N][3];
/*
dp[x][y][0]: x-y的最大值
dp[x][y][1]: x-y均添一样的值
*/
int main(){
    freopen("zht","r",stdin);
    //freopen("color.in","r",stdin);
    //freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 1; i <= n ;i++){
            cin>>a[i];
        }
        for(int i = 1; i < n; i++){
            if(a[i] == a[i + 1]) dp[i][i + 1][0] = dp[i][i + 1][1] = a[i];
            dp[i][i + 1][2] = 0;
        }
        for(int len = 3; len <= n; len++){
            for(int l = 1; l <= n - len + 1; l++){
                int r = l + len - 1;
                if(a[l] == a[l + 1]) dp[l][r][1] = dp[l + 1][r][1] + a[l];
                else dp[l][r][1] = dp[l + 1][r][1];
                dp[l][r][0] = dp[l + 1][r][0];
                for(int i = l + 1; i <= r; i++){
                    if(a[i] == a[l]){
                        dp[l][r][0] = max(dp[l][r][0],dp[l + 1][i - 1][1] + a[l] + dp[i - 1][r][2]);
                        break;
                    }
                }
                if(a[l] != a[l + 1]) dp[l][r][2] = dp[l][r][0];
                else{
                    for(int i = l + 2; i <= r; i++){
                        if(a[i] == a[l]){
                            dp[l][r][0] = max(dp[l][r][0], dp[l + 1][i - 1][1] + a[l] + dp[i - 1][r][2]);
                            break;
                        }
                    }
                }
            }
        }
        /*for(int l = 1; l < n; l++){
            for(int r = l + 1; r <= n; r++){
                cout<<l<<" "<<r<<" "<<dp[l][r][0]<<endl;
            }
        }*/
        cout<<dp[1][n][0]<<endl;
    }
    return 0;
}
