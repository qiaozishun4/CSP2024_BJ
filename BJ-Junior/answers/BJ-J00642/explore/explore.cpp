#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
const int fx[4]={0,1,0,-1};
const int fy[4]={1,0,-1,0};
int T,n,m,k,vis[N][N];
char c[N][N];
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[i][j]=0;
        }
    }
}
int x,y,d;
void dfs(){
    if(k<=0) return;
    vis[x][y]=1,k--;
    x=x+fx[d];
    y=y+fy[d];
    while(c[x][y]=='.' && x>=1 && x<=n && y>=1 && y<=m){
        vis[x][y]=1,k--;
        if(k<0) return;
        x+=fx[d],y+=fy[d];
    }
    vis[x][y]=0;
    x-=fx[d],y-=fy[d];
    d=(d+1)%4;
    dfs();
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        init();
        for(int i=1;i<=n;i++){
            scanf("%s",c[i]+1);
        }
        dfs();
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=vis[i][j];
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}

