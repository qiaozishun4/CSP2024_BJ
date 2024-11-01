#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
const int N=1e3+10;
int n,m,k,n1,m1;
int x,y,d,ans;
char mp[N][N];
bool vis1[N][N];
bool vis[N][N][4];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
signed main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));ans=0;
        memset(vis1,0,sizeof(vis1));
        cin>>n>>m>>k;n1=n;m1=m;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        if(mp[x][y+1]=='x'&&mp[x][y-1]=='x'&&mp[x+1][y]=='x'&&mp[x-1][y]=='x'){
            cout<<1<<endl;
            continue;
        }
        vis1[x][y]=1;ans++;
        while(k--){
            int nx,ny;
            nx=x+dx[d];ny=y+dy[d];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]!='x'){
                x=nx;y=ny;
            }else{
                d=(d+1)%4;
            }
            if(!vis1[x][y]){
                ans++;
                vis1[x][y]=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
