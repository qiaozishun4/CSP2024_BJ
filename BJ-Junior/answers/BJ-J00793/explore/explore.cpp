#include<bits/stdc++.h>
using namespace std;
bool mapp[1005][1005],vis[1005][1005];
int xx[]={0,1,0,-1},yy[]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int n,m,k,x,y,d,ans=1;
        char r;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        memset(mapp,0,sizeof(mapp));
        memset(vis,0,sizeof(vis));
        vis[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>r;
                if(r=='.') mapp[i][j]=1;
            }
        }
        for(int i=1;i<=k;i++){
            if(mapp[x+xx[d]][y+yy[d]]==0){
                d=(d+1)%4;
                continue;
            }
            x+=xx[d];
            y+=yy[d];
            //cout<<x<<y<<endl;
            if(vis[x][y]==0) {ans++;vis[x][y]=1;}
        }
        cout<<ans<<endl;
    }
    return 0;
}