#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=2e5+10;
typedef long long ll;
int n,v=1e5,sum,maxl;
ll f[2][2][MAXN];
int a[MAXN];
void Work(){
    memset(f,0,sizeof(f));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=1;j++){
            for(int k=0;k<i;k++){
                ll val=f[(i-1)&1][j][k];
                if(a[i-1]==a[i]) val+=a[i];
                f[i&1][j][k]=max(f[i&1][j][k],val);
                if(k==i-1){
                    for(int l=0;l<i-1;l++){
                        ll val=f[(i-1)&1][j^1][l];
                        if(a[l]==a[i]) val+=a[i];
                        f[i&1][j][k]=max(f[i&1][j][k],val);
                    }
                }
                ans=max(ans,f[i&1][j][k]);
            }
        }
    }
    
    //for(int i=0;i<=n;i++) ans=max(ans,f[n][j]);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;cin>>t;
    while(t--) Work();
    return 0;
}