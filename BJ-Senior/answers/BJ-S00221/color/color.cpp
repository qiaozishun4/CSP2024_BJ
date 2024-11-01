//Wrote by Timmy in October 26th
//I wish I could have 100 points in this problem
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int mx[1000010][2],mx2[2];
int dp[N][2],a[N],w[2];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t; cin>>t;
    while (t--){
        memset(mx,-0x3f,sizeof(mx));
        memset(mx2,0,sizeof(mx2));
        int n; cin>>n; w[0]=w[1]=0; a[n+1]=1e6+5;
        for (int i=1; i<=n; i++) cin>>a[i];
        for (int i=1; i<=n; i++){
            for (int j=0; j<2; j++){
                w[j]+=(a[i]==a[i-1])*a[i];
                mx2[j]=max(mx2[j],dp[i-1][j^1]-w[j]);
                mx[a[i-1]][j]=max(mx[a[i-1]][j],dp[i-1][j^1]-w[j]);
                dp[i][j]=max(mx2[j],mx[a[i+1]][j]+a[i+1])+w[j];
            }
        }cout<<max(dp[n][0],dp[n][1])<<"\n";
    }return 0;
}
