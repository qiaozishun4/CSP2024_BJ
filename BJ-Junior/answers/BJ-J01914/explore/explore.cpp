#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,sx,sy,sd,x,y,d,vis[1002][1002],sum;
char s[1002][1002];
int f[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    //freopen("explore5.in","r",stdin);
    //freopen("explore5.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        sum=1;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&sx,&sy,&sd);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>s[i][j];
                vis[i][j]=0;
            }
        }
        x=sx;
        y=sy;
        d=sd;
        vis[sx][sy]=1;
        for(int i=1;i<=k;i++){
            int lx=x+f[d][0];
            int ly=y+f[d][1];
            if(s[lx][ly]!='x'&&lx<=n&&lx>=1&&ly<=m&&ly>=1){
                if(!vis[lx][ly]){
                    vis[lx][ly]=1;
                    sum++;
                }
                x=lx;
                y=ly;
            }else{
                d++;
                d%=4;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
