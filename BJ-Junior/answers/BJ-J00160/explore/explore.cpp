#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool G[1005][1005];
bool vis[1005][1005];
char bkup[1005][1005];
int ans=0;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        ans=0;
        int n=0,m=0,k=0;
        int x=0,y=0,d=0;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        cin>>n>>m>>k>>x>>y>>d;
        memset(G,0x00,sizeof(G));
        memset(vis,0x00,sizeof(vis));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>bkup[i][j];G[i][j]=(bkup[i][j]!='.');
        }}
        vis[x][y]=true,ans++;
        for(int i=1;i<=k;i++)
        {
            int xx=x+dx[d];
            int yy=y+dy[d];
            if(xx<1||xx>n||yy<1||yy>m)  {d+=1;d=d%4;continue;}
            if(bkup[xx][yy]!='.')   {d+=1;d=d%4;continue;}
            x=xx,y=yy;
            if(!vis[x][y]) ans++,vis[x][y]=true;
        }
        cout<<ans<<endl;
    }

    return 0;
}
