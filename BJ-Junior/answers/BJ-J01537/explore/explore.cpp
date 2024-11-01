#include<bits/stdc++.h>
using namespace std;
int n,m,T,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},ans,d,k,x,y;
bool mp[1024][1024];bool vis[1024][1024];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        n=0;
        m=0;
        x=0;
        y=0;
        k=0;
        d=0;
        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='x'){
                mp[i][j]=1;
            }
        }
        vis[x][y]=1;ans=1;
        for(int i=1;i<=k;i++){
            int curx=x+dx[d];
            int cury=y+dy[d];
            if(curx<=n&&curx>=1&&cury<=m&&cury>=1&&mp[curx][cury]==0){
                x=curx;
                y=cury;
                if(vis[x][y]==0){
                    ans++;
                }
                vis[x][y]=1;
            }else{
                d=(d+1)%4;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
