#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y,d;
char g[1005][1005];
bool vis[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
                cin>>g[i][j];
            }
        }

        vis[x][y]=1;
        int ans=1;
        while(k--){

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
            else if(d==3){
                nx=x-1;
                ny=y;
            }
            if(nx>n||nx<1||ny>m||ny<1||g[nx][ny]=='x'){
                d=(d+1)%4;
                continue;
            }
            else{
                x=nx;
                y=ny;
                if(!vis[x][y]){
                    vis[x][y]=1;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}