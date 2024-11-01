#include<iostream>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,k;
        int x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        bool mp[n+2][m+2],vis[n+1][m+1];
        mp[0][0]=0;
        mp[n+1][m+1]=0;
        for(int j=1;j<=n;j++){
            mp[j][0]=0;
            mp[j][m+1]=0;
            for(int l=1;l<=m;l++){
                char aa;
                cin>>aa;
                if(aa=='.'){
                    mp[j][l]=1;
                }
                else{
                    mp[j][l]=0;
                }
                vis[j][l]=0;
            }
        }
        for(int j=1;j<=m;j++){
            mp[0][j]=0;
            mp[n+1][j]=0;
        }
        vis[x][y]=1;
        int nowx=x,nowy=y;
        for(int j=1;j<=k;j++){
            if(mp[nowx+dx[d]][nowy+dy[d]]==1){
                nowx+=dx[d];
                nowy+=dy[d];
                vis[nowx][nowy]=1;
            }
            else{
                d=(d+1)%4;
            }
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                if(vis[j][l]==1){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
