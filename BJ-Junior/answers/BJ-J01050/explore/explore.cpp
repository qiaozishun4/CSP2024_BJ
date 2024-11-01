#include<iostream>
using namespace std;
#define LL long long
bool vis[1010][1010];
char mp[1010][1010];
LL wk[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
LL n,m,k,ans;
void slove(){
    cin>>n>>m>>k;
    LL x0,y0,d0;
    cin>>x0>>y0>>d0;
    getchar();
    for(LL i=1;i<=n;i++){
        for(LL j=1;j<=m;j++){
            mp[i][j]=getchar();
            vis[i][j]=0;
        }
        getchar();
    }
    ans=0;
    int x=x0,y=y0,d=d0,step=k;
    while(step>=0){
        if(!vis[x][y])ans++,vis[x][y]=1;
        if(step==0)break;
        step--;
        LL x1=x+wk[d%4][0],y1=y+wk[d%4][1];
        if(1<=x1&&x1<=n&&1<=y1&&y1<=m&&mp[x1][y1]=='.')x=x1,y=y1;
        else d=(d+1)%4;
    }
    cout<<ans<<endl;
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    LL T;cin>>T;
    while(T--)slove();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
