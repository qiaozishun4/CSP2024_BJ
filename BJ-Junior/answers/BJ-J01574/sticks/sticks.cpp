#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
ll n;
ll dp[1000005],a[10];
ll getlen(ll x){
    ll returnans=0;
    while(x!=0){
        x=x/10;
        returnans++;
    }
    return returnans;
}
ll changeto(ll x){
    ll ans[20],now=0,len=getlen(x),ra=0;
    while(x!=0){
        now++;
        ans[len-now+1]=x%10;
        x/=10;
    }
    ra=ans[1];
    for(ll i=2;i<=len;i++){
        if(ans[i]==6){
            ans[i]=0;
        }
        ra=ra*10+ans[i];
    }
    return ra;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(ll t=1;t<=T;t++){
        cin>>n;
        memset(dp,0x3f,sizeof(dp));
        if(n<2){
            cout<<"-1";
            continue;
        }
        dp[2]=1;a[1]=2;
        dp[5]=2;a[2]=5;
        dp[4]=4;a[4]=4;
        dp[6]=6;a[6]=6;
        dp[3]=7;a[7]=3;
        dp[7]=8;a[8]=7;
        a[0]=6;
        ll temp10=10;
        for(ll i=2;i<=n;i++){
            for(ll j=2;j<=7;j++){
                ll h=pow(temp10,getlen(max(dp[i],dp[j])));
                dp[i+j]=min(dp[i+j],min(dp[i],dp[j])*h+max(dp[i],dp[j]));
                dp[i+j]=changeto(dp[i+j]);
            }

        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
