#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,M=1e8;
int n,ans,dp[N];
int v[10]={6,2,5,5,4,5,6,3,7,6};
//         0 1 2 3 4 5 6 7 8 9
int w[10]={1,7,4,2,3,5,0,6,9,8};
void solve(){
    //dp[i]:i根木棍能拼成的最小的数;
    //转移：dp[i]=min(dp[i],dp[i-v[w[i]]]*10+w[i]);
    memset(dp,0x3f,sizeof(dp));
    cin>>n;
    if(n<2){
        cout<<"-1"<<endl;
        return;
    }
    dp[0]=0;
    for(int i=2;i<=n;i++){
        for(int j=0;i-v[w[j]]>=0&&j<10;j++){
            if(w[j]==0&&dp[i-v[w[j]]]==0){
                continue;
            }
            dp[i]=min(dp[i],dp[i-v[w[j]]]*10+w[j]);
        }
    }
    if(dp[n]>M){
        cout<<-1;
        return;
    }
    cout<<dp[n]<<endl;
    return;
}
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}