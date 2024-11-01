#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char a[1005][1005];
bool vis[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]=0;
                vis[i][j]=0;
            }
        }
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        vis[x][y]=1;
        for(int i=1;i<=k;i++){
            if(x+dx[d]<1||y+dy[d]<1||x+dx[d]>n||y+dy[d]>m||a[x+dx[d]][y+dy[d]]=='x'){
                d=(d+1)%4;
                continue;
            }
            x+=dx[d];
            y+=dy[d];
            if(vis[x][y]==0){
                ans++;
                vis[x][y]=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
