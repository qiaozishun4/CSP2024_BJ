#include<iostream>
using namespace std;
int t,n,m,k,x,y,d,ans;
int vis[1010][1010];
char a[1010][1010];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)vis[i][j]=0;
        }
        vis[x][y]=1;
        while(k--){
            if(x+dx[d]>0&&x+dx[d]<=n&&y+dy[d]>0&&y+dy[d]<=m&&a[x+dx[d]][y+dy[d]]=='.')x+=dx[d],y+=dy[d],vis[x][y]=1;
            else d=(d+1)%4;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j])ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
