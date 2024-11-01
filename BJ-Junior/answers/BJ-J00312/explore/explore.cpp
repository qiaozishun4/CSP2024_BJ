#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int t,n,m,k,xx,yy,dd,ans;
char c[1005][1005];
bool vis[1005][1005],flag[1005][1005][4];
void dfs(int x,int y,int z,int step)
{
    if(flag[x][y][z])return;
    flag[x][y][z]=1;
    vis[x][y]=1;
    if(step>=k)
    {
        return;
    }
    else if(c[x+dx[z]][y+dy[z]]=='.')
    {
        dfs(x+dx[z],y+dy[z],z,step+1);
        return;
    }
    else
    {
        dfs(x,y,(z+1)%4,step+1);
        return;
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int I=1;I<=t;I++)
    {
        cin>>n>>m>>k>>xx>>yy>>dd;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
            }
        }
        dfs(xx,yy,dd,0);
        for(int i=1;i<=1000;i++)
        {
            for(int j=1;j<=1000;j++)
            {
                c[i][j]='x';
                if(vis[i][j])ans++;
                vis[i][j]=0;
                flag[i][j][0]=0;
                flag[i][j][1]=0;
                flag[i][j][2]=0;
                flag[i][j][3]=0;
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
