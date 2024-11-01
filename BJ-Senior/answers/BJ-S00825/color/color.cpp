#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N],s[N],dp[N][2];
long long ans;
void dfs(int u,int state){
    if(u>n){
        int pre0=0,pre1=0;
        long long res=0;
        for(int i=1;i<=n;i++){
            if(state&(1<<i-1)){
                if(a[i]==a[pre1]) res+=a[i];
                pre1=i;
            }else{
                if(a[i]==a[pre0]) res+=a[i];
                pre0=i;
            }
        }
        ans=max(ans,res);
        return;
    }
    dfs(u+1,state|(1<<u-1));
    dfs(u+1,state);
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));memset(s,0,sizeof(s));memset(dp,0,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==a[i-1]) s[i]=s[i-1]+a[i];
            else s[i]=s[i-1];
        }
        if(n<=15){
            ans=0;
            dfs(1,0);
            cout<<ans<<'\n';
            continue;
        }
        dp[1][0]=dp[1][1]=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i][0]=max(dp[i][0],dp[j][0]+s[i-1]-s[j+1]+(a[i]==a[j]?a[i]:0));
                dp[i][0]=max(dp[i][0],dp[j][1]+s[i]-s[j+1]);
                dp[i][1]=max(dp[i][1],dp[j][1]+s[i-1]-s[j+1]+(a[i]==a[j]?a[i]:0));
                dp[i][1]=max(dp[i][1],dp[j][0]+s[i]-s[j+1]);
            }
        }
        cout<<max(dp[n][0],dp[n][1])<<'\n';
    }
    return 0;
}
