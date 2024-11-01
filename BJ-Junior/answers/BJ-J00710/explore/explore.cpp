#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1005][1005],vis[1005][1005];
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void dfs(int x,int y,int d,int cnt,int num){
    if(vis[x][y]==0){
        num++,vis[x][y]=1;
    }
    if(cnt==k){
        cout<<num<<endl;
        return ;
    }
    if(x+dx[d]<=n&&x+dx[d]>=1&&y+dy[d]>=1&&y+dy[d]<=m&&a[x+dx[d]][y+dy[d]]==0){
        dfs(x+dx[d],y+dy[d],d,cnt+1,num);
    }
    else dfs(x,y,(d+1)%4,cnt+1,num);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        char c;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c;
                if(c=='.') a[i][j]=0;
                else a[i][j]=1;
            }
        }
        dfs(x,y,d,0,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
    }
    return 0;
}
