#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char mp[1005][1005];
int v[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int ans=0,n,m,k,x,y,d;
        memset(v,0,sizeof(v));
        memset(mp,' ',sizeof(mp));
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf(" %c",&mp[i][j]);
        for(int i=0;i<=k;i++){
            v[x][y]=1;
            int nx,ny;
            if(d==0)nx=x,ny=y+1;
            if(d==1)nx=x+1,ny=y;
            if(d==2)nx=x,ny=y-1;
            if(d==3)nx=x-1,ny=y;
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.')
                x=nx,y=ny;
            else d=(d+1)%4;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(v[i][j]==1)ans++;
        printf("%d\n",ans);
    }
    return 0;
}
