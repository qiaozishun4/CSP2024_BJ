#include<bits/stdc++.h>
using namespace std;
//dp[i][j] i with same color score
const int N=2e3+5;
int dp[N][N],max_dp[N];
int n,a[N];
int t;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        memset(dp,0,sizeof dp);
        memset(max_dp,0,sizeof max_dp);
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        dp[1][1]=0;
        max_dp[1]=0;
        for(int i=2;i<=n;i++){
            int cnt_max=-1;
            for(int j=1;j<=i;j++){
                if(j==1){
                    int cnt=i-2;
                    while(a[cnt]!=a[i]&&cnt>=1) cnt--;
                    if(cnt!=0){
                        int can_add=0;
                        for(int x=cnt+2;x<=i-1;x++){
                            if(a[x]==a[x-1]) can_add+=a[x];
                        }
                        for(int x=1;x<=cnt;x++){
                            dp[i][j]=max(dp[i][j],dp[cnt][x]+can_add+(a[cnt-x]==a[cnt+1]?a[cnt+1]:0)+a[cnt]);
                        }
                    }
                    dp[i][j]=max(dp[i][j],max_dp[i-1]);
                    cnt_max=max(cnt_max,dp[i][j]);
                    continue;
                }
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+(a[i]==a[i-1]?a[i]:0));
                cnt_max=max(cnt_max,dp[i][j]);
            }
            max_dp[i]=cnt_max;
        }
        cout<<max_dp[n]<<endl;
    }
    return 0;
}
