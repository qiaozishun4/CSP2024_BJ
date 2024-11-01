#include<iostream>
#include<cstring>
using namespace std;
const int N=1024;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
char mp[N][N];
bool vis[N][N];
int t,n,m,k,x,y,d,ans;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        memset(mp,'x',sizeof(mp));
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>mp[i][j];
        vis[x][y]=1;
        while(k--){
            if(mp[x+dx[d]][y+dy[d]]=='.'){
                x+=dx[d];
                y+=dy[d];
                vis[x][y]=1;
            }
            else d=(d+1)%4;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                ans+=vis[i][j];
        cout<<ans<<endl;
    }
    return 0;
}