#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
#define int long long
int t,n,a[maxn],cnt[maxn],las[maxn],dp[maxn][2],num[maxn<<4];
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            las[i]=num[a[i]];
            num[a[i]]=i;
            cnt[i]=(a[i]==a[i-1]?cnt[i-1]+a[i]:cnt[i-1]);
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            if(las[i]){
                dp[i][1]=max(dp[las[i]][0],dp[las[i]][1])+cnt[i-1]-cnt[las[i]]+a[i];
                if(las[i]+1!=i){
                    dp[i][1]=max(dp[i][1],dp[las[i]+1][1]+cnt[i-1]-cnt[las[i]]+a[i]);
                }
            }
        }
        cout<<max(dp[n][0],dp[n][1])<<'\n';
    }
    return 0;
}
