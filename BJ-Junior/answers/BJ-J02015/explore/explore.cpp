#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int T,n,m,k,x,y,d;
bool f[maxn][maxn];
char c[maxn][maxn];
bool inb(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=m&&c[x][y]=='.';
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        memset(f,0,sizeof(f));
        f[x][y]=1;
        for(int i=1;i<=k;i++){
            int nx=x+dx[d],ny=y+dy[d];
            if(inb(nx,ny)) x=nx,y=ny;
            else d=(d+1)%4;
            f[x][y]=1;
            //cout<<i<<" "<<x<<" "<<y<<" "<<d<<'\n';
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j]) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
