#include<bits/stdc++.h>
using namespace std;
char s[1005][1005];
int vis[1005][1005];
int cnt=0;
int go[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    int T;cin>>T;
    while(T--){
        int n,m,k;cin>>n>>m>>k;
        int x,y,d;cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>s[i][j];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)vis[i][j]=0;
        }
        cnt=1;
        vis[x][y]=1;
        for(int i=1;i<=k;i++){
            int nx=x+go[d][0],ny=y+go[d][1];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&s[nx][ny]=='.'){
                x=nx;y=ny;
                if(vis[x][y]==0)cnt++;
                vis[x][y]=1;
            }else{
                d=(d+1)%4;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
