#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,y,x,d,dd[5][5] = {{0,1},{1,0},{0,-1},{-1,0}};
bool vis[1005][1005];
char a[1005][1005];
string s;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int sum=1;
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        vis[x][y] = 1;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            for(int j=0;j<m;j++)
            {
                a[i][j+1] = s[j];
            }
        }
        for(int i=1;i<=k;i++)
        {
            int xx=x+dd[d][0],yy=y+dd[d][1];
            if(xx>0&&xx<=n&&yy>0&&yy<=m&&a[xx][yy]=='.')
            {
                if(vis[xx][yy]==0)
                {
                    sum++;
                    vis[xx][yy] = 1;
                }
                x = xx;
                y = yy;
            }
            else
            {
                d++;
                d %= 4;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}