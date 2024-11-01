#include<bits/stdc++.h>
#define rd(x) scanf("%lld",&x)
using namespace std;
typedef long long ll;
ll cnt,T,n,m,k,x,y,d,h[1005][1005];
char a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;cnt++;
        cin>>x>>y>>d;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        h[x][y]=cnt;
        while(k--){
            ll nx=x,ny=y;
            if(d==0) ny++;
            if(d==1) nx++;
            if(d==2) ny--;
            if(d==3) nx--;
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.') x=nx,y=ny;
            else d=(d+1)%4;
            h[x][y]=cnt;
        }
        ll ans=0;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++) ans+=(h[i][j]==cnt);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
