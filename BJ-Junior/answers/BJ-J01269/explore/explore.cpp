#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int x,y,d;
char a[1005][1005];
bool vis[1005][1005];
int res;

void walk(){
    int nx,ny;
    if(d==0)
        nx=x,ny=y+1;
    if(d==1)
        nx=x+1,ny=y;
    if(d==2)
        nx=x,ny=y-1;
    if(d==3)
        nx=x-1,ny=y;

    if(1<=nx&&nx<=n && 1<=ny&&ny<=m && a[nx][ny]=='.')
        x=nx,y=ny;
    else d=(d+1)%4;
    if(!vis[x][y]) res++;
    vis[x][y]=1;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        getchar();

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%c",&a[i][j]);
        while(k--)
            walk();

        cout<<res<<' ';
    }
    return 0;
}
