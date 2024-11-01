#include <iostream>
#include <cstdio>
using namespace std;

int T,m,n,x0,y0,d0,k,count_grid;
char maps[1003][1003];
bool vis[1003][1003];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    for(int i=0;i<=T;i++){
        for(int i=0;i<=1003;i++){
            for(int j=0;j<=1003;j++){
                vis[i][j]=false;
            }
        }
        count_grid=1;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x0,&y0,&d0);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                scanf("%c",&maps[i][j]);
            }
        }
        for(int i=1;i<=k;i++){
            vis[x0][y0]=true;
            if(maps[x0+dx[d0]][y0+dy[d0]]!='x' && x0+dx[d0]>=1 && x0+dx[d0]<=n && y0+dy[d0]>=1 && y0+dy[d0]<=m){
                x0=x0+dx[d0];
                //printf("%d ",x0);
                y0=y0+dy[d0];
                //printf("%d \n",y0);
                if(vis[x0][y0]==false){
                    count_grid++;
                }
            }
            else{
                d0=(d0+1)%4;
            }
        }
        printf("%d\n",count_grid);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
