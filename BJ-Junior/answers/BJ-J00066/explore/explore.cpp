#include <bits/stdc++.h>
using namespace std;
const int N=1005;
bool a[N][N],v[N][N];
int xx[10]={0,1,0,-1};
int xy[10]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(v,0,sizeof(v));
        int n,m,k;
        cin>>n>>m>>k;
        int stx,sty,stc;
        cin>>stx>>sty>>stc;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if(c=='x')
                {
                    a[i][j]=1;
                }
            }
        }
        v[stx][sty]=1;
        for(int i=1;i<=k;i++)
        {
            int nx=stx+xx[stc];
            int ny=sty+xy[stc];
            if(nx>n || nx<1 || ny>m || ny<1 || a[nx][ny]==1)
            {
                stc=(stc+1)%4;
            }
            else
            {
                stx=nx;
                sty=ny;
                v[stx][sty]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(v[i][j]==1)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
