#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int T,n,m,k;
int x,y,d,ans;
char a[maxn][maxn];
int vis[maxn][maxn];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        ans=0;
        memset(vis,0,sizeof(vis));
        vis[x][y]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        for(int i=1;i<=k;i++){
            if(d==0){
                if(y+1>=1&&y+1<=m&&a[x][y+1]!='x'){
                    vis[x][y+1]=1;
                    y+=1;
                }
                else d=(d+1)%4;
            }
            else if(d==1){
                if(x+1>=1&&x+1<=n&&a[x+1][y]!='x'){
                    vis[x+1][y]=1;
                    x+=1;
                }
                else d=(d+1)%4;
            }
            else if(d==2){
                if(y-1>=1&&y-1<=m&&a[x][y-1]!='x'){
                    vis[x][y-1]=1;
                    y-=1;
                }
                else d=(d+1)%4;
            }
            else if(d==3){
                if(x-1>=1&&x-1<=n&&a[x-1][y]!='x'){
                    vis[x-1][y]=1;
                    x-=1;
                }
                else d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1)ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
