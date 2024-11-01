#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
char s[1010][1010];
int t,n,m,k,x,y,d;
int dx,dy,ans=1;
struct base{int x,y;};
bool vis[1010][1010];
void bfs(int x,int y){
    queue<base>Q;
    Q.push({x,y});
    vis[x][y]=1;
    while(k--){
        base a=Q.front();Q.pop();
        int x=a.x,y=a.y;
        int nx=x+dx,ny=y+dy,tim=4;
        while(nx<1||nx>n||ny<1||ny>m||s[nx][ny]=='x'){
            k--,tim--,d=(d+1)%4;
            if(d==0)dx=0,dy=1;
            else if(d==1)dx=1,dy=0;
            else if(d==2)dx=0,dy=-1;
            else if(d==3)dx=-1,dy=0;
            if(!tim||k<0){
                printf("%d",ans);
                ans=1;return;
            }
            nx=x+dx,ny=y+dy;
        }
        Q.push({nx,ny});
        if(!vis[nx][ny])ans++;
        vis[nx][ny]=1;
    }
    printf("%d",ans);ans=1;
    memset(vis,0,sizeof(vis));
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        if(d==0)dx=0,dy=1;
        else if(d==1)dx=1,dy=0;
        else if(d==2)dx=0,dy=-1;
        else if(d==3)dx=-1,dy=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf(" %c",&s[i][j]);
        bfs(x,y);printf("\n");
    }return 0;
}
