#include<iostream>
#include<vector>
using namespace std;
#define MAXN 200005
typedef long long ll;
vector<ll> f[MAXN];
vector<bool> g[MAXN];
int T,n,a[MAXN];
void solve(){
    int maxcol=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxcol=max(maxcol,a[i]);
    }
    for(int i=0;i<=n;i++) f[i].clear(),g[i].clear();
    if(n<=2005) for(int i=0;i<=n;i++){
        f[i].reserve(2005),g[i].reserve(2005);
    }
    else for(int i=0;i<=n;i++) f[i].reserve(13),g[i].reserve(13);
    for(int i=0;i<=n;i++) for(int j=0;j<=maxcol;j++) f[i][j]=g[i][j]=0;
    g[0][0]=1;
    for(int i=1;i<=n;i++){
        int y=a[i-1];
        for(int x=0;x<=maxcol;x++){
            if(g[i-1][x]){
                f[i][y]=max(f[i][y],f[i-1][x]+a[i]*(a[i]==x));
                f[i][x]=max(f[i][x],f[i-1][x]+a[i]*(a[i]==y));
                g[i][y]=g[i][x]=1;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=maxcol;i++) ans=max(ans,f[n][i]);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--) solve();
    return 0;
}