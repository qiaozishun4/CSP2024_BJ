#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,m,k,sx,sy,sd,ans;
bool v[1005][1005],f;
char c[1005][1005];
void dfs(int x,int y,int step,int d){
    if(f) return;
    if(step==k){
        f=1;
        return;
    }
    int nx,ny;
    if(d==0) nx=x,ny=y+1;
    else if(d==1) nx=x+1,ny=y;
    else if(d==2) nx=x,ny=y-1;
    else nx=x-1,ny=y;
    if(nx>=1 && nx<=n && ny>=1 && ny<=m && c[nx][ny]=='.') v[nx][ny]=1,dfs(nx,ny,step+1,d);
    else dfs(x,y,step+1,(d+1)%4);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        memset(v,0,sizeof(v));
        ans=0;
        f=0;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&sx,&sy,&sd);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> c[i][j];
        v[sx][sy]=1;
        dfs(sx,sy,0,sd);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(v[i][j]) ans++;
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
