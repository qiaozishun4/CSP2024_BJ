#include<bits/stdc++.h>
#define rd(x) scanf("%lld",&x)
using namespace std;
typedef long long ll;
const ll N=1e6+5;
ll T,n,x,cnt,p[N],a[N],s[N],dp[N],h[N];
inline ll cal(ll l,ll r){
    if(l>r) return 0;
    return s[r]-s[l-1];
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    rd(T);
    while(T--){
        rd(n);
        for(ll i=1;i<=n;i++) rd(a[i]),p[a[i]]=0,s[i]=s[i-1]+(a[i]==a[i-1])*a[i],dp[i]=0;
        dp[0]=0;
        for(ll i=1;i<=n;i++){
            dp[i]=dp[i-1];
            if(p[a[i]]){
                dp[i]=max(dp[i],max(dp[p[a[i]]+1],dp[p[a[i]]])+cal(p[a[i]]+1,i-1)+a[i]);
            }
            p[a[i]]=i;
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}
