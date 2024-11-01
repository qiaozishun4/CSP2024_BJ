#include<bits/stdc++.h>
using namespace std;
char mp[10010][10010];
bool vis[10010][10010];
int dx[5]={1,0,-1,0};
int dy[5]={0,1,0,-1};
int t,n,m,k,x,y,d,cnt;
void dfs(int x,int y){
    int sum=0;
    for(int i=0;i<4;i++) {
        if(sum>=k){
            cnt++;
            return ;
        }
        int nx=x+dx[i];
        int ny=y+dy[i];
        /*
        if(nx<1||ny<1||ny>m||nx>n ||mp[nx][ny]=='x') {
            for(int i=1;i<=3;i++) {
                nx=x+dx[d+i];
                ny=y+dy[d+i];
                if(nx>0&&ny>0&&mp[nx][ny]=='.') {
                    break;
                }
            }
        }
        */
        if(mp[nx][ny]=='.'&&nx>0&&ny>0&&nx<=n&&ny<=m&&!vis[nx][ny]) {
            vis[nx][ny]=true;
            cnt++;
            sum++;
            dfs(nx,ny);
        }
    }
}
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >>t;
    for(int i1=1;i1<=t;i1++) {
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>mp[i][j];
            }
        }
        cin>>x>>y>>d;
        vis[x][y]=false;
        dfs(x,y);
        cout <<cnt<<endl;
        cnt=0;
    }
}