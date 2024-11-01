#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
int bx[4]={0,1,0,-1};
int by[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i]+1;
        }
        while(k--){
            vis[x][y]=1;
            int nx=x+bx[d],ny=y+by[d];
            if(nx>n||ny>m||nx<1||ny<1||a[nx][ny]=='x'){
                d=(d+1)%4;
                continue;
            }
            x=nx;
            y=ny;
        }
        vis[x][y]=1;
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1){
                    cnt++;
                    vis[i][j]=0;
                }
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
