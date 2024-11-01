#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int dx[5]={0,1,0,-1};
const int dy[5]={1,0,-1,0};

bool canmove[1005][1005];
bool vis[1005][1005];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(canmove,0,sizeof(canmove));
        memset(vis,0,sizeof(vis));
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        char c;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin>>c;
                canmove[i][j]=(c=='.');
            }
        }for(int i=0;i<=n+1;++i){
            canmove[i][0]=canmove[i][m+1]=false;
        }for(int j=0;j<=m+1;++j){
            canmove[0][j]=canmove[n+1][j]=false;
        }int ans=1;
        vis[x][y]=true;
        for(int i=1;i<=k;++i){
            int xx=x+dx[d];
            int yy=y+dy[d];
            if(!canmove[xx][yy]){
                d=(d+1)%4;
            }else{
                x=xx;
                y=yy;
            }if(!vis[x][y]){
                ++ans;
            }vis[x][y]=true;
        }cout<<ans<<'\n';
    }return 0;
}
