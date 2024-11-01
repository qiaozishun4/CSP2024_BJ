#include<iostream>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    for(scanf("%d",&T);T;T--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int x,y,d;
        scanf("%d%d%d",&x,&y,&d);
        char a[n+2][m+2]={0};
        bool vis[n+1][m+1]={0};
        const int xd[4]={0,1,0,-1};
        const int yd[4]={1,0,-1,0};
        for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
        vis[x][y]=1;
        long long ans=1;
        while(k--){
            if(/*(x+xd[d]>m||y+yd[d]>n||x+xd[d]<1||y+yd[d]<1)&&*/a[x+xd[d]][y+yd[d]]!='.'){
                d=(d+1)%4;
                continue;
            }
            //if(cnt>0) continue;
            x+=xd[d],y+=yd[d];
            if(!vis[x][y]) ans++;
            vis[x][y]=1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}