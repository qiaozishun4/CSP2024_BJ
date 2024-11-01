#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,nx,ny,d,ans;
char a[1005][1005];
bool vis[1005][1005];
inline int nextx(const int &x,const int &d){
    if(d==0) return x;
    if(d==1) return x+1;
    if(d==2) return x;
    return x-1;
}
inline int nexty(const int &y,const int &d){
    if(d==0) return y+1;
    if(d==1) return y;
    if(d==2) return y-1;
    return y;
}
inline bool can(const int &x,const int &y){return x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]=='.';}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        memset(vis,false,sizeof(vis));
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
        vis[x][y]=true;
        while(k--){
            nx=nextx(x,d);
            ny=nexty(y,d);
            if(can(nx,ny)) vis[x=nx][y=ny]=true;
            else d=(d+1)%4;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans+=vis[i][j];
        printf("%d\n",ans);
    }
    return 0;
}
