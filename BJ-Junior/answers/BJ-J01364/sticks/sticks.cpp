#include<bits/stdc++.h>
using namespace std;

//int a[10][2] = {{0, 6}, {1, 2}, {2, 5}, {4, 4}, {6, 6}, {7, 3}, {8, 7}};
int a[15] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18};
int q = 9;
vector<int> dp(100005, INT_MAX);
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    //memset(dp, 999, sizeof(dp));
    for (int i=0;i<=9;i++) dp[i] = a[i];
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        for (int i=10;i<=n;i++){
            for (int j=2;j<=q;j++){
                if (dp[j] == -1 || dp[i-j] == -1) continue;
                int x = j;
                if (x == 6) x = 0;
                dp[i] = min(dp[i], stoi(to_string(dp[i-j]) + to_string(dp[x])));
                if (dp[i] == 268) cout<<i<<' '<<j<<endl;
            }
            q++;
        }
        if (dp[n] == INT_MAX){
            cout<<-1<<endl;
            continue;
        }
        cout<<dp[n]<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
