#include<bits/stdc++.h>
using namespace std;
long long T,n,m,k,x,y,op,sum;
bool vis[1005][1005],mp[1005][1005];
char c;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        sum=0;
        memset(vis,false,sizeof(vis));
        scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&k,&x,&y,&op);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                mp[i][j]=false;
                scanf(" %c",&c);
                if(c=='x'){
                    mp[i][j]=true;
                }
            }
        }
        vis[x][y]=true;
        for(int i=1;i<=k;i++){
            long long nx,ny;
            if(op==0){
                nx=x,ny=y+1;
            }
            else if(op==1){
                nx=x+1,ny=y;
            }
            else if(op==2){
                nx=x,ny=y-1;
            }
            else if(op==3){
                nx=x-1,ny=y;
            }
            if(nx>=1 && nx<=n && ny>=1 && ny<=m && mp[nx][ny]==false){
                x=nx,y=ny;
                vis[x][y]=true;
            }
            else{
                op=(op+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==true)sum++;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}