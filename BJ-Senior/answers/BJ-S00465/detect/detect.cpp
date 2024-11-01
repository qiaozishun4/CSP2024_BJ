#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100001,L=1000001;
int n,m,l,V;
int d[N],v[N],a[N];
int p[N];
int f[L],g[L];
int h[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>l>>V;
        for(int i=0;i<=l;i++)f[i]=g[i]=0;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++){
            cin>>p[i];
            f[p[i]]=g[p[i]]=i;
            h[i]=0;
        }
        for(int i=1;i<=l;i++)if(!f[i])f[i]=f[i-1];
        for(int i=l;i>=1;i--)if(!g[i-1])g[i-1]=g[i];
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]>V){
                    if(g[d[i]])ans++,h[m]=max(h[m],g[d[i]]);
                }
            }
            if(a[i]>0){
                if(v[i]>V){
                    if(g[d[i]])ans++,h[m]=max(h[m],g[d[i]]);
                }
                else{
                    ll k=d[i]+(1ll*V*V-1ll*v[i]*v[i])/(2*a[i])+1;
                    if(k<=l&&g[k])ans++,h[m]=max(h[m],g[k]);
                }
            }
            if(a[i]<0){
                if(v[i]>V){
                    ll k=d[i]+(1ll*v[i]*v[i]-1ll*V*V-1)/(-2*a[i]);
                    if(k>l)k=l;
                    if(g[d[i]]<=f[k])ans++,h[f[k]]=max(h[f[k]],g[d[i]]);
                }
            }
        }
        cout<<ans<<' ';
        ans=0;
        int now=0;
        for(int i=1;i<=m;i++)if(now<h[i])now=i,ans++;
        cout<<m-ans<<'\n';
    }
    return 0;
}
