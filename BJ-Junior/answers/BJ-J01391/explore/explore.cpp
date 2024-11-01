#include<bits/stdc++.h>
using namespace std;
bool a[1005][1005],vis[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        int n,m,k,x,y,d;
        char c;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c;
                if(c=='x'){
                    a[i][j]=1;
                }
                else{
                    a[i][j]=0;
                }
            }
        }
        for(int i=1;i<=k;i++){
            int nx,ny;
            if(d==0){
                nx=x;
                ny=y+1;
            }
            else if(d==1){
                nx=x+1;
                ny=y;
            }
            else if(d==2){
                nx=x;
                ny=y-1;
            }
            else{
                nx=x-1;
                ny=y;
            }
            if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]){
                d=(d+1)%4;
            }
            else{
                x=nx;
                y=ny;
                vis[x][y]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
