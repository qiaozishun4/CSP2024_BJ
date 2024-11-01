#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3fll
#define maxn 2000
using namespace std;
int t,n,cnt,dp[1000001],a[200001],p[1000001],ans,lst[200001];
void upd(int&x,int y){
    x=max(x,y);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        memset(p,0,sizeof(p));
        memset(dp,0,sizeof(dp));
        ans=0;
        cin>>n;
        cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(p[a[i]]){
                lst[i]=p[a[i]];
            }else{
                lst[i]=0;
            }
            p[a[i]]=i;
            if(a[i]==a[i-1]){
                cnt+=a[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(lst[i]&&lst[i]!=i-1){
                upd(dp[a[i-1]],dp[a[i]]+a[i]);
            }
            upd(dp[a[i-1]],ans);
            upd(ans,dp[a[i-1]]);
        }
        cout<<ans+cnt<<endl;
    }
}
