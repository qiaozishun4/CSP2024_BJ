#include<bits/stdc++.h>
using namespace std;
char mp[1001][1001];
bool vis[1001][1001];
int t,n,m,k,x,y,d;
int dx[5];
int dy[5];
void mst(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) vis[i][j]=0;
    }
}
void dfs(int x,int y,int d,int cnt,int cnt2){
    if(cnt==k){
        printf("%d\n",cnt2);
        return;
    }
    int xx,yy;
    if(d==0) xx=x+1,yy=y;
    else if(d==1) xx=x,yy=y+1;
    else if(d==2) xx=x-1,yy=y;
    else xx=x,yy=y-1;
    if(xx>=1&&xx<=m&&yy>=1&&yy<=n&&mp[yy][xx]=='.'&&vis[yy][xx]==0){
        vis[yy][xx]=1;
        dfs(xx,yy,d,++cnt,++cnt2);
    }else if(xx>=1&&xx<=m&&yy>=1&&yy<=n&&mp[yy][xx]=='.'&&vis[yy][xx]==1){
        dfs(xx,yy,d,++cnt,cnt2);
    }else{
        dfs(x,y,(d+1)%4,++cnt,cnt2);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mst();
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int j=1;j<=n;j++){
            for(int g=1;g<=m;g++) cin>>mp[j][g];
        }
        dfs(x,y,d,0,1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}