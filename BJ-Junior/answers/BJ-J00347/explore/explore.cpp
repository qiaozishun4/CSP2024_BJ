#include <iostream>
#include <cstring>
using namespace std;
int t;
int n,m,k;
bool visited[1005][1005];
char ma[1005][1005];
int fwx[5]={0,1,0,-1};
int fwy[5]={1,0,-1,0};
int ans;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    for(int tt=1;tt<=t;tt++)
    {
        cin >> n >> m >> k;
        int x,y,d;
        cin >> x >> y >> d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> ma[i][j];
            }
        }
        memset(visited,0,sizeof(visited));
        visited[x][y]=true;
        ans=1;
        for(int i=1;i<=k;i++)
        {
            int xx=x+fwx[d];
            int yy=y+fwy[d];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&ma[xx][yy]=='.')
            {
                x=xx;
                y=yy;
                if(visited[x][y]==false)
                {
                    ans++;
                }
                visited[x][y]=true;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
