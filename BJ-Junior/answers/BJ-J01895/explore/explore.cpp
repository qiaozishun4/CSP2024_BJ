#include <bits/stdc++.h>
using namespace std;
const int N = 1145;
int T,n,m,vis[N][N];
char s[N][N];
bool f(int &x,int &y,int &d){
    int xx=x,yy=y;
    //cout<<d<<'\n';
    if(d==0) yy=y+1;
    if(d==1) xx=x+1;
    if(d==2) yy=y-1;
    if(d==3) xx=x-1;
    //cout<<xx<<' '<<yy<<' '<<s[xx][yy]<<1<<' '<<vis[xx][yy]<<'\n';
    if(xx<=n&&yy<=m&&xx>=1&&yy>=1&&s[xx][yy]=='.'&&vis[xx][yy]==0){
        x=xx,y=yy,vis[xx][yy]=1;
        //cout<<x<<' '<<y<<'\n';
        return 1;
    }
    else if(xx<=n&&yy<=m&&xx>=1&&yy>=1&&s[xx][yy]=='.'&&vis[xx][yy]==1){
        x=xx,y=yy,vis[xx][yy]=1;
        //cout<<x<<' '<<y<<'\n';
        return 0;
    }
    else{
        d=(d+1)%4;
        //cout<<d<<'\n';
        return 0;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        memset(vis,0,sizeof vis);
        int ans=0;
        int k,x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>s[i][j];
            }
        }
        if(k==0) {cout<<1<<'\n';continue;}
        for(int i=1;i<=k;i++){
            //cout<<i<<' ';
            if(f(x,y,d)) ans++;
            //cout<<ans<<'\n'<<'\n';
        }
        cout<<ans+1<<'\n';
    }
    return 0;
}
