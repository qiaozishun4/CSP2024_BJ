#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;
const int K=1e6+10;

int T,n,m,d,x,y,k,a[N][N],vis[N][N];

int go(int x,int y,int k,int d,int ans)
{

    if(vis[x][y]==0)
    {
        vis[x][y]=1;
        ans++;
    }
    if(k==0)return ans;
    if(d==0)y++;
    if(d==1)x++;
    if(d==2)y--;
    if(d==3)x--;
    if(a[x][y]==1||x<1||y<1||x>n||y>m)
    {
        if(d==0)y--;
        if(d==1)x--;
        if(d==2)y++;
        if(d==3)x++;
        d++;
        d%=4;
    }
    go(x,y,k-1,d,ans);
}


int main()
{
    freopen("explore.in","r",stdin);freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if(c=='x')a[i][j]=1;
            }
        }
        cout<<go(x,y,k,d,0)<<"\n";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                a[i][j]=0;
                vis[i][j]=0;
            }
        }
    }
    return 0;
}
