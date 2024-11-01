#include <iostream>
#include <algorithm>
using namespace std;
char g[1010][1010];
int a[1010][1010];
int gx[4]={0,1,0,-1};
int gy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        int lx,ly,ld;
        cin >> lx >> ly >> ld;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> g[i][j];
                a[i][j]=0;
            }
        }
        a[lx][ly]=1;
        for(int i=1;i<=k;i++)
        {
            int nx,ny,nd;
            nx=lx+gx[ld];
            ny=ly+gy[ld];
            nd=ld;
            if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]=='x')
            {
                nx=lx;
                ny=ly;
                nd=(ld+1)%4;
            }
            else    a[nx][ny]=1;
            lx=nx;
            ly=ny;
            ld=nd;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]==1)  ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}