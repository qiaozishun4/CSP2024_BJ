#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k;
int x,y,d;
char p[1005][1005];
bool vis[1005][1005];
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>p[i][j];
            }
        }
        vis[x][y]=true;
        while(k--){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&p[nx][ny]!='x'){
                vis[nx][ny]=true;
                x=nx;
                y=ny;
            }
            else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]) ans++;
            }
        }
        cout<<ans<<endl;
        memset(vis,false,sizeof(vis));
    }
    return 0;
}
