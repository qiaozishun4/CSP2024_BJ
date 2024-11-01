#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,k;
bool vis[1005][1005];
bool f[1005][1005];
void dfs(int x,int y,int d,int step){
    if(step==k+1)return;
    vis[x][y]=1;
    int x2=x+dx[d];
    int y2=y+dy[d];
    if(x2<1||x2>n||y2<1||y2>m||f[x2][y2])dfs(x,y,(d+1)%4,step+1);
    else dfs(x2,y2,d,step+1);
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                if(c=='x'){
                    f[i][j]=1;
                }
            }
        }
        while(k--){
            vis[x][y]=1;
            int x2=x+dx[d];
            int y2=y+dy[d];
            if(x2<1||x2>n||y2<1||y2>m||f[x2][y2])d=(d+1)%4;
            else x=x2,y=y2;
            vis[x][y]=1;
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=0;
                if(vis[i][j]){
                    ans++;
                }
                vis[i][j]=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}