#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,ans=1;
char c[5000][5000];
int vs[5000][5000];
void dfs(int x,int y,int d,int cnt)
{
 //   cout<<"ddd "<<x<<' '<<y<<' '<<ans<<' '<<cnt<<'\n';
 //   vs[x][y]=1;
    if(cnt==k)
    {
        return ;
    }
    int cx,cy;
    if(d==0)
    {
        cx=x;
        cy=y+1;
    }
    else if(d==1)
    {
        cx=x+1;
        cy=y;
    }
    else if(d==2)
    {
        cx=x;
        cy=y-1;
    }
    else if(d==3)
    {
        cx=x-1;
        cy=y;
    }
 //   cout<<"kkk   "<<cx<<' '<<cy<<' '<<vs[cx][cy]<<'\n';
    if(cx>=1&&cx<=m&&cy>=1&&cy<=n&&c[cx][cy]=='.')
    {
        if(vs[cx][cy]==0)
        {
            vs[cx][cy]=1;
            ans++;
        }
        dfs(cx,cy,d,cnt+1);
    }
    else
    {
        if(d==3)
        {
            d=-1;
        }
        dfs(x,y,d+1,cnt+1);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int cnt=0,i,j;
        ans=1;
        cin>>m>>n>>k;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                vs[i][j]=0;
            }
        }
        cin>>x>>y>>d;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>c[i][j];
            }
        }
 //       cout<<x<<' '<<y<<' '<<d<<'\n';
        vs[x][y]=1;
        dfs(x,y,d,cnt);
        cout<<ans<<'\n';
 //       cout<<"-------------\n";
     //   cout<<ds<<'\n';
    }
    return 0;
}
