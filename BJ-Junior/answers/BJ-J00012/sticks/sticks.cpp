#include <bits/stdc++.h>
using namespace std;

int c[] = {0, 6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int w[] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
const int N = 1e5 + 5;
int dp[10][N];


int stick(int n){
        if(n == 1) return -1;
        for(int i = 2; i <= 10; i++){
                for(int j = 1; j <= n; j++){
                        if(c[i] >= j) dp[i][j] = max(dp[i - 1][j], (dp[i][j - c[i]] * 10) + w[i]);
                        else dp[i][j] = dp[i - 1][j];
                }
        }
        return dp[10][n];
}

int main(){
        freopen("stick.in", "w", stdin);
        freopen("stick.out", "r", stdout);
        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                cout << stick(n) << endl;
        }
        fclose(stdin);
        fclose(stdout);
        return 0;
}
