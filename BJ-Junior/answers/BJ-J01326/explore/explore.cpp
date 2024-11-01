#include <bits/stdc++.h>
using namespace std;

int t,n,m,k,x,y,d,ans,tx,ty;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool vis[1145][1145],a[1145][1145];
char temp;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                {
                    vis[i][j]=0;
                }

        vis[x][y]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                {
                    cin >> temp;
                    if(temp=='x')a[i][j]=1;
                    else a[i][j]=0;
                }

        for(int i=1;i<=k;i++)
        {
            tx=x+dx[d];
            ty=y+dy[d];
            if(!a[tx][ty] && tx>=1 && tx<=n && ty>=1 && ty<=m)
                x=tx,y=ty,vis[x][y]=1;
            else d++;
            if(d>=4)d=0;
        }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                {
                    if(vis[i][j])ans++;
                }

        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}