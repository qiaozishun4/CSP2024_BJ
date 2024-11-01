#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1;
int t,n,a[N],chr,chb,dp[N][2],rer,reb,ber,beb,cr0,cr1,cb0,cb1;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        memset(dp,0,sizeof dp);
        rer=reb=ber=beb=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cr0=((a[i]!=a[rer])?0:a[i]);
            cr1=((a[i]!=a[ber])?0:a[i]);
            cb0=((a[i]!=a[reb])?0:a[i]);
            cb1=((a[i]!=a[beb])?0:a[i]);
            chr=max(cr0+dp[i-1][0],cr1+dp[i-1][1]);
            chb=max(cb0+dp[i-1][0],cb1+dp[i-1][1]);
            reb=((cr0+dp[i-1][0]>cr1+dp[i-1][1])?reb:beb);
            ber=((cb0+dp[i-1][0]>cb1+dp[i-1][1])?rer:ber);
            rer=i,beb=i;
            dp[i][0]=chr,dp[i][1]=chb;
        }
        cout<<max(dp[n][0],dp[n][1])<<'\n';
    }
    return 0;
}

