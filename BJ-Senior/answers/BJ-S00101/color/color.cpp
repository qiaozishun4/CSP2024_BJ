#include<iostream>
using namespace std;

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int timesss;
    cin >> timesss;
    for(int asdf =0; asdf<timesss; asdf++){
        int n;
        cin >> n;
        int val[n+10];
        int maxval=0;
        val[0] = 0;
        for(int i=1; i<=n;i++){
            cin >> val[i];
            if(val[i] > maxval){
                maxval = val[i];
            }
        }

        int dp[n+10][maxval+10];

        for(int i=0; i<=maxval;i++){
            dp[0][i] = -0x3f3f3f3f;
        }
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=maxval; j++){
                dp[i][j] = dp[i-1][j];
                if(val[i] == j){
                    dp[i][j] = max(dp[i][j], 0);
                }
                if(val[i] == val[i-1]){
                    dp[i][j] = dp[i-1][j] + val[i];
                }
            }
            for(int j=1; j<=maxval; j++){
                dp[i][val[i-1]] = max(dp[i][val[i-1]], dp[i-1][val[i]] + val[i]);

            }
            //for(int j=1; j<=maxval; j++){
            //    cout << dp[i][j] <<" ";
            //}
            //cout << "\n";
        }

        int maxscore = 0;
        for(int i=1; i<=maxval; i++){
            maxscore = max(maxscore, dp[n][i]);
        }

        cout << maxscore << "\n";
    }
}
