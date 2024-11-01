#include <bits/stdc++.h>
using namespace std;
int a[1010][1010],n,nx,ny,x,y,d,m,k,T,ans,vis[1010][1010];
char c;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans=1;
        scanf("%d %d %d %d %d %d",&n,&m,&k,&x,&y,&d);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                vis[i][j]=0;
                a[i][j]=0;
                cin>>c;
                if(c=='x') a[i][j]=1;
            }
        }
        vis[x][y]=1;
        while(k--){
            if(d==0){
                nx=x;
                ny=y+1;
            }else if(d==1){
                nx=x+1;
                ny=y;
            }else if(d==2){
                nx=x;
                ny=y-1;
            }else if(d==3){
                nx=x-1;
                ny=y;
            }
            if(a[nx][ny]==1 || nx<1 || nx>n || ny<1 || ny>m){
                d++;
                d%=4;
            }else{
                x=nx;
                y=ny;
                if(vis[nx][ny]==0){
                    ans++;
                    vis[nx][ny]=1;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
