#include <bits/stdc++.h>
#define N 200002
using namespace std;
int n,a[N],dp[N][2],S[N][2];
void solve1(){
    int ans=0;
    for(int k=0;k<(1<<n);k++){
        int res=0;
        for(int i=0;i<n;i++){
            int pos=-1;
            for(int j=i-1;j>=0;j--){
                if(!(((k>>j)&1)^((k>>i)&1))){
                    pos=j;
                    break;
                }
            }
            if(pos==-1)  continue;
            if(a[pos+1]==a[i+1])  res+=a[i+1];
        }
        ans=max(ans,res);
    }
    cout<<ans<<"\n";
}
void solve2(){
    memset(dp,0,sizeof dp);
    memset(S,0,sizeof S);
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i]==a[j])  dp[i][0]=max(dp[j-1][0]+a[i],dp[i][0])+(S[i][1]-S[j-1][1]);
            else  dp[i][0]=max(dp[i][0],dp[j-1][0])+(S[i][1]-S[j-1][1]);
        }
        for(int j=1;j<i;j++){
            if(a[i]==a[j])  dp[i][1]=max(dp[j-1][1]+a[i],dp[i][1])+(S[i][0]-S[j-1][0]);
            else  dp[i][1]=max(dp[i][1],dp[j-1][1])+(S[i][0]-S[j-1][0]);
        }
        S[i+1][0]=S[i][0]+dp[i][0];
        S[i+1][1]=S[i][1]+dp[i][1];
        // cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<S[i][0]<<" "<<S[i][1]<<"\n";
    }
    cout<<max(dp[n][0],dp[n][1])<<"\n";
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)  cin>>a[i];
        if(n<=15)  solve1();
        else  solve2();
    }
    return 0;
}