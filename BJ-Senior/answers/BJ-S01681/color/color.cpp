#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[200005],n,i,t,k,b[1000005],l[200005],s[200005],dp[200005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(k=1;k<=t;k++){
        cin>>n;
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            l[i]=b[a[i]];
            b[a[i]]=i;
            s[i]=s[i-1];
            if(a[i]==a[i-1]){
                s[i]+=a[i];
            }
        }
        for(i=1;i<=n;i++){
            dp[i]=dp[i-1];
            if(l[i]!=0){
                dp[i]=max(dp[i],dp[l[i]+1]+s[i-1]-s[l[i]]+a[i]);
            }
        }
        cout<<dp[n]<<endl;
        memset(b,0,sizeof(b));
        memset(l,0,sizeof(l));
        memset(dp,0,sizeof(dp));
        memset(s,0,sizeof(s));
    }
    return 0;
}
