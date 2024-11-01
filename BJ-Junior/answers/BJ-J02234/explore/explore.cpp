#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int dx[5]={0,1,0,-1};
int dy[5]={1,0,-1,0};
bool vis[1105][1105];
char maze[1105][1105];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;int n,m,k;int x,y,d;long long ans;
    char ge;
    cin>>t;
    for(int i=1;i<=t;i++){
        memset(vis,0,sizeof(vis));
        ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                cin>>ge;
                maze[j][l]=ge;
            }
        }
        ans++;
        vis[x][y]=1;
        for(int j=1;j<=k;j++){
            if(x+dx[d]>n or x+dx[d]<1 or y+dy[d]>m or y+dy[y]<1 or maze[x+dx[d]][y+dy[d]]!='.'){
                d=d+1;
                d%=4;
                continue;
            }
            x+=dx[d];
            y+=dy[d];
            if(vis[x][y]==0){
                vis[x][y]=1;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
