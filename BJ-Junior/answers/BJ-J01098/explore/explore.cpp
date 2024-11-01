#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int sx,sy,sd;
char a[1005][1005];
bool vis[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int step,cnt;
int dfs(int x,int y){
    if(step==k){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    else{
        int nx=x+dx[sd];
        int ny=y+dy[sd];
        if(nx>=1&&ny>=1&&nx<=n&&ny<=m&&a[nx][ny]=='.'){
            step++;
            vis[nx][ny]=1;
            return dfs(nx,ny);
        }
        else{
            sd=(sd+1)%4;
            step++;
            return dfs(x,y);
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int kkk=0;kkk<t;kkk++){
        cin>>n>>m>>k;
        cin>>sx>>sy>>sd;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        vis[sx][sy]=1;
        step=0;
        cnt=0;
        cout<<dfs(sx,sy)<<endl;
    }
    return 0;
}
