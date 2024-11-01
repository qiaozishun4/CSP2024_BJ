#include <iostream>
using namespace std;
int t,m,n,vis[1001][1001];
char a[1001][1001];
int dx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        int day,xx,yy,d,ans=0;
        cin>>m>>n>>day;
        cin>>xx>>yy>>d;
        for (int j=1;j<=m;j++)
            for (int k=1;k<=n;k++)
                cin>>a[j][k];
        for (int j=1;j<=day;j++)
        {
            vis[xx][yy]=1;
            if (!(xx+dx[d][0]<=m&&xx+dx[d][0]>0&&yy+dx[d][1]<=n&&yy+dx[d][1]>0&&a[xx][yy]!='x'))
                d=(d+1)%4;
            xx+=dx[d][0];
            yy+=dx[d][1];
        }
        for (int j=1;j<=m;j++)
            for (int k=1;k<=n;k++)
                if (vis[j][k]) ans++;
        cout<<ans+1<<endl;
        for (int j=1;j<=m;j++)
            for (int k=1;k<=n;k++)
                vis[j][k]=0;
    }
    return 0;
}
