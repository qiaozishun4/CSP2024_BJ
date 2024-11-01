#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e3;
int T,n,m,k,x,y,d,vis[N+5][N+5],ans;
char s[N+5][N+5];
pair<int,int> nnext(int xx,int yy,int dd)
{
    if(dd==0) return {xx,yy+1};
    else if(dd==1) return {xx+1,yy};
    else if(dd==2) return {xx,yy-1};
    else if(dd==3) return {xx-1,yy};
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                vis[i][j]=0;
        vis[x][y]=1;
        for(int i=1;i<=n;i++)
            cin>>(s[i]+1);
        for(int i=1;i<=k;i++)
        {
            pair<int,int> now=nnext(x,y,d);
            int xx=now.first,yy=now.second;
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&s[xx][yy]=='.')
                x=xx,y=yy,vis[xx][yy]=1;
            else d=(d+1)%4;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(vis[i][j]==1)
                    ans++;
        printf("%d\n",ans);
    }
    return 0;
}
