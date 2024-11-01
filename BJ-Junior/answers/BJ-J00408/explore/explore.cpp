#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e3+5;
char a[N][N];
bool vis[N][N];
int n,m,k,ans;
inline int nxtx(int x,int d){
    if(d==0) return  x;
    if(d==1) return  x+1;
    if(d==2) return  x;
    if(d==3) return  x-1;
}
inline int nxty(int y,int d){
    if(d==0) return  y+1;
    if(d==1) return  y;
    if(d==2) return  y-1;
    if(d==3) return  y;
}
bool check(int x,int y){
    return x>0&&x<=n&&y>0&&y<=m&&a[x][y]!='x';
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        ans=0;
        int x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        vis[x][y]=1;
        while(k){
            //cout<<x<<' '<<y<<'\n';
            while(!check(nxtx(x,d),nxty(y,d))){
                d=(d+1)%4;
                --k;
                if(k==0) break;
            }
            if(k==0) break;
            x=nxtx(x,d),y=nxty(y,d);
            vis[x][y]=1;
            k--;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
