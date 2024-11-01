#include<iostream>
using namespace std;
int vis[1005][1005];
char a[1005][1005];
int dx[4]={+0,+1,+0,-1};
int dy[4]={+1,+0,-1,+0};
int main(){
    ios::sync_with_stdio(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        vis[x][y]=1;
        while(k--){
            int tx=x+dx[d];
            int ty=y+dy[d];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]=='.'){
                x=tx;
                y=ty;
                vis[x][y]=1;
            }
            else{
                d=(d+1)%4;
            }
        }
        long long sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum+=vis[i][j];
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}
