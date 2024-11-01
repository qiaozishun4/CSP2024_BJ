#include<queue>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int k,n,m,t;
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
char g[1005][1005];
bool vis[1005][1005];
struct node{
    int x,y,step,d;
}now;
void bfs(int x,int y,int d,int step){
    for(int i=1;i<=1003;++i){
        for(int j=1;j<=1003;++j){
            vis[i][j]=0;
        }
    }
    vis[x][y]=1;
    queue<node>q;
    q.push((node){x,y,d,0});
    while(!q.empty()){
        now=q.front();
        q.pop();
        vis[now.x][now.y]=1;
        if(now.step==k){
            continue;
        }
        int xx=now.x+dx[now.d];
        int yy=now.y+dy[now.d];
        if(xx>0&&yy>0&&xx<=n&&yy<=m&&g[xx][yy]=='.'){
            q.push((node){xx,yy,now.step+1,now.d});
        }else{
            q.push((node){now.x,now.y,now.step+1,(now.d+1)%4});
        }
    }int ans=0;
    for(int i=1;i<=100;++i){
        for(int j=1;j<=100;++j){
            if(vis[i][j]){
                ++ans;
            }
        }
    }printf("%d\n",ans);
    return;
}
int main(){
   freopen("explore.in","r",stdin);
   freopen("explore.out","w",stdout);
    scanf("%d",&t);
    int x,y,d;
    string s;
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;++i){
            cin>>s;
            for(int j=1;j<=m;++j){
                g[i][j]=s[j-1];
            }
        }bfs(x,y,d,0);
    }
    return 0;
}

