#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int T,n,m,k,sx,sy,sd,nx,ny,nd,ans;
int mapn[1005][1005];
bool vis[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        n=0,m=0,k=0,ans=0;
        cin>>n>>m>>k;
        cin>>sx>>sy>>sd;
        memset(mapn,-1,sizeof(mapn));
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    char k;
                    cin>>k;
                    mapn[i][j]=(k=='.'?1:0);
            }
        }
        vis[sx][sy]=true;
        ans+=1;
        nx=sx,ny=sy,nd=sd;
        while(k--){
            int fx,fy,fd;
            if(nd==0) fx=nx,fy=ny+1;
            if(nd==1) fx=nx+1,fy=ny;
            if(nd==2) fx=nx,fy=ny-1;
            if(nd==3) fx=nx-1,fy=ny;

            fd=nd;
            //check
            if(fx<1||fy<1||fx>n||fy>m||mapn[fx][fy]==0||mapn[fx][fy]==-1){
                fd=(nd+5)%4;
                fx=nx,fy=ny;
            }

            if(vis[fx][fy]==false){
                ans++;
                vis[fx][fy]=true;
            }

            nx=fx,ny=fy,nd=fd;
        }
        cout<<ans<<endl;
    }
    return 0;


}
