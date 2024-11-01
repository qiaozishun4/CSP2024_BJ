#include <bits/stdc++.h>
using namespace std;
int a[200005],dp[200005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,ans=0;cin>>n;
        int mask=(1<<n);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=0;i<mask;i++){
            int res=0;
            for(int j=1;j<=n;j++){
                int k=j-1;
                while((((i>>(k-1))&1)!=((i>>(j-1))&1))&&k) k--;
                if(((i>>(k-1))&1)!=((i>>(j-1))&1)) continue;
                if(a[j]==a[k]) res+=a[j];
            }
            ans=max(ans,res);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//CSP-S rp++;
