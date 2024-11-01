#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N=1005;
int T, n, m, k, vis[N][N];
char ch[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        int x, y, d;
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>ch[i][j];
        int ans=1;
        memset(vis,0,sizeof(vis));
        vis[x][y]=1;
        for(int i=1;i<=k;i++){
            int xi, yi;
            if(d==0) xi=x, yi=y+1;
            if(d==1) xi=x+1, yi=y;
            if(d==2) xi=x, yi=y-1;
            if(d==3) xi=x-1, yi=y;
            if(xi>=1&&xi<=n&&yi>=1&&yi<=m&&ch[xi][yi]=='.'){
                x=xi, y=yi;
                if(vis[x][y]==0) vis[x][y]=1, ans++;
            }else d=(d+1)%4;
        }
        printf("%d\n",ans);
    }
    return 0;
}