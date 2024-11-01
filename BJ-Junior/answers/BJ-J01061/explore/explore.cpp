#include<iostream>
using namespace std;
int t,n,m,k,x,y,d;
char a[1001][1001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool vis[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        vis[x][y]=1;
        for(int i=1;i<=k;i++){
            int xx=x+dx[d],yy=y+dy[d];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
                x=xx;
                y=yy;
                vis[x][y]=1;
            }else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
