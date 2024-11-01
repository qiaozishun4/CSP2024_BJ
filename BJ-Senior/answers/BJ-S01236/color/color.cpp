#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[1000009][2];
int a[1000009];
void _main(){
    memset(dp,-0x3f,sizeof(dp));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0][0]=dp[0][1]=0;
    int ma0,p,ma1;
    ma0=ma1=0,p=0;
    for(int i=2;i<=n;i++){
        int m0,m1;
        m0=ma0+p;
        m1=ma1+p;
        m0=max(dp[a[i]][0]+p+a[i],m0);
        m1=max(dp[a[i]][1]+p+a[i],m1);
        if(a[i]==a[i-1]){
            p+=a[i];
        }
        m0-=p,m1-=p;
        dp[a[i-1]][1]=max(dp[a[i-1]][1],m0);
        dp[a[i-1]][0]=max(dp[a[i-1]][0],m1);
        ma0=max(ma0,dp[a[i-1]][0]);
        ma1=max(ma1,dp[a[i-1]][1]);
    }
    int ans;
    ans=0;
    ans=max(ma0+p,ma1+p);
    cout<<ans<<endl;
}
signed main(){
    std::ios::sync_with_stdio(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        _main();
    }
    return 0;
}
