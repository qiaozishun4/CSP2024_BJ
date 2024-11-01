#include <bits/stdc++.h>
using namespace std;

int use[10] = {6,2,5,5,4,5,6,3,7,6};
int dp[100010];

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 1;i <= 100010;i++){
            dp[i] = 2147483647;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= 9;j++){
                if(j==0&&i-use[j]==0)continue;
                if(i>=use[j]&&dp[i-use[j]]!=2147483647){
                    dp[i] = min(dp[i-use[j]]*10+j,dp[i]);
                }
            }
        }
        if(dp[n]==2147483647)cout << "-1\n";
        else cout << dp[n] << "\n";
    }
    return 0;
}
