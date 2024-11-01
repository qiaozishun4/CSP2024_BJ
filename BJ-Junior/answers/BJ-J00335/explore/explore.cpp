#include<bits/stdc++.h>
using namespace std;

const int N=1e3+3;
bool vis[N][N];
char g[N][N];

int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    int n,m,k,x,y,d,nx,ny,nd,tot=0;
    bool flag=false;
    while(T--) {
        flag=false;
        tot=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>g[i][j];
                if(g[i][j]=='x') flag=true;
                vis[i][j]=false;
            }
        }
        //cout<<"ok"<<endl;
        if(n==1) {
            for(int j=1;j<=m;j++) {
                if(g[1][j]=='x') {
                    cout<<j-y-1<<endl;
                    break;
                }
            }
            continue;
        }
        //cout<<"enter"<<endl;
        for(int t=1;t<=k;t++) {
        //cout<<x<<" "<<y<<" "<<d<<" "<<tot<<endl;
        if(x>=1&&x<=n&&y>=1&&y<=m) {
            if(!vis[x][y]) {
                vis[x][y]=true;
                tot++;
            }
        }
        if(d==0) nx=x,ny=y+1;
        else if(d==1) nx=x+1,ny=y;
        else if(d==2) nx=x,ny=y-1;
        else if(d==3) nx=x-1,ny=y;
        //cout<<nx<<" "<<ny<<endl;
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m) {
            if(g[nx][ny]=='.') {
                x=nx,y=ny;
            }
            else {
                d=(d+1)%4;
            }
        }
        else {
            d=(d+1)%4;
        }
    }
    if(nx>=1&&nx<=n&&ny>=1&&ny<=m) {
            if(g[nx][ny]=='.') {
                tot++;
            }
        }
    cout<<tot<<endl;
    }
    return 0;
}
