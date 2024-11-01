#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,k,d,Max;
int mov[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[N][N];
bool vis[N][N];
bool in(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m) return true;
    return false;
}
void dfs(int x,int y,int step,int mo)
{
    for(int i=0;i<4;i++)
    {
        if(mo==k)
        {
            Max=max(Max,step);
            return;
        }
        int xx=x+mov[d][0],yy=y+mov[d][1];
        if(in(xx,yy)&&s[xx][yy]=='.')
        {
            if(vis[xx][yy]) step++;
            vis[xx][yy]=false;
            dfs(xx,yy,step,mo+1);
            vis[xx][yy]=true;
            return;
        }
        d=(d+1)%4;
        mo++;
    }
    return;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,xx,yy;
    cin>>T;
    while(T--)
    {
        Max=1;
        memset(s,' ',sizeof(s));
        memset(vis,true,sizeof(vis));
        cin>>n>>m>>k>>xx>>yy>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>s[i][j];
            }
        }
        vis[xx][yy]=false;
        dfs(xx,yy,1,0);
        cout<<Max<<endl;
    }
    return 0;
}
