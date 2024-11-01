#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=-0x3f3f3f3f;
long long a[N],dp[2][N][2];//[id][the last different color id][red or blue]
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        int n;
        cin>>n;
        for (int i=1;i<=n;i++) {
            cin>>a[i];
        }
        for (int i=0;i<=n;i++) {
            dp[1][i][0]=dp[1][i][1]=inf;
        }
        dp[1][0][0]=0;
        long long tmp0=0,tmp1=inf;
        for (int i=2;i<=n;i++) {
            dp[0][i][1]=0;
            long long now0=inf,now1=inf;
            for (int j=0;j<i-1;j++) {//same of the last
                dp[0][j][0]=max(dp[0][j][0],dp[1][j][0]+(a[i-1]==a[i] ? a[i] : 0));
                dp[0][j][1]=max(dp[0][j][1],dp[1][j][1]+(a[i-1]==a[i] ? a[i] : 0));
                now0=max(now0,dp[0][j][0]+(a[j]==a[i+1] ? a[j] : 0));
                now1=max(now1,dp[0][j][1]+(a[j]==a[i+1] ? a[j] : 0));
            }//different of the last
            dp[0][i-1][0]=max(dp[0][i-1][0],tmp1);
            dp[0][i-1][1]=max(dp[0][i-1][1],tmp0);
            now0=max(now0,dp[0][i-1][0]+(a[i-1]==a[i+1] ? a[i-1] : 0));
            now1=max(now1,dp[0][i-1][1]+(a[i-1]==a[i+1] ? a[i-1] : 0));
            swap(now0,tmp0);
            swap(now1,tmp1);
            swap(dp[0],dp[1]);


            /*for (int j=0;j<i;j++) {
                cout<<dp[1][j][0]<<' '<<dp[1][j][1]<<endl;
            }
            cout<<endl;*/

        }
        cout<<max(tmp0,tmp1)<<'\n';
    }
    return 0;
}
