#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,sx,sy,sd;
int vis[1006][1006];
char a[1006][1006];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>sx>>sy>>sd;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int x=sx,y=sy,d=sd;
        vis[sx][sy]=1;
        while(k--){
            int nx=0,ny=0,nd=0;
            if(d==0){
                nx=x;
                ny=y+1;
                nd=d;
            }else if(d==1){
                nx=x+1;
                ny=y;
                nd=d;
            }else if(d==2){
                nx=x;
                ny=y-1;
                nd=d;
            }else if(d==3){
                nx=x-1;
                ny=y;
                nd=d;
            }
            if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x'){
                d=(d+1)%4;
            }else{
                vis[nx][ny]=1;
                x=nx;
                y=ny;
                d=nd;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=vis[i][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
