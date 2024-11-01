#include<bits/stdc++.h>
using namespace std;
int t;
char a[1005][1005];
bool vis[1005][1005];
int n,m,k,x,y,d;
int hang[]={0,1,0,-1};
int lie[]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%c",&a[i][j]);
            }
        }
        vis[x][y]=true;
        while(k>0){
            int nx=x+hang[d];
            int ny=y+lie[d];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]!='X'){
                x=nx;
                y=ny;
                k--;
                vis[nx][ny]=true;
            }else{
                k--;
                d=(d+1)%4;
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==true){
                    res++;
                    vis[i][j]=false;
                }
            }
        }
        printf("%d",res);
    }
    return 0;
}