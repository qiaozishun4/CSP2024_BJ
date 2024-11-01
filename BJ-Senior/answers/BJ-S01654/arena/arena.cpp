#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+10;
ll T,n,a[maxn],ans;
ll c[maxn],l[maxn];
void dfs(ll x){
    if(x==n+1){
        ll cnt=0,p=0,q=0;
        for(ll i=1;i<=n;i++){
            if(c[i]==1){
                if(a[i]==p) cnt+=a[i];
                p=a[i];
            }else{
                if(a[i]==q) cnt+=a[i];
                q=a[i];
            }
        }
        ans=max(ans,cnt);
        return;
    }
    c[x]=1;
    dfs(x+1);
    c[x]=2;
    dfs(x+1);
    c[x]=0;
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        ans=0;
        memset(c,0,sizeof(c));
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}

