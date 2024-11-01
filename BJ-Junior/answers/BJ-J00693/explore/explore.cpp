#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("explore.in");
ofstream cout("explore.out");
bool vis[1001][1001];
bool mapl[1001][1001];
int T,n,m,k,x,y,xo,yo,d,ans,nxtx,nxty;
char c;
int main()
{
    cin>>T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        ans=0;
        cin>>n>>m>>k;
        cin>>xo>>yo>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                if(c=='.')
                    mapl[i][j]=0;
                if(c=='x')
                    mapl[i][j]=1;
            }
        }
        x=xo,y=yo;
        ans=1;
        vis[xo][yo]=true;
        while(k--)
        {
            if(d==0)
            {
                nxtx=x;
                nxty=y+1;
            }
            if(d==1)
            {
                nxtx=x+1;
                nxty=y;
            }
            if(d==2)
            {
                nxtx=x;
                nxty=y-1;
            }
            if(d==3)
            {
                nxtx=x-1;
                nxty=y;
            }
            if(mapl[nxtx][nxty]==1||nxtx<=0||nxtx>n||nxty<=0||nxty>m)
            {
                d=(d+1)%4;
            }
            else
            {
                x=nxtx;
                y=nxty;
                if(!vis[x][y])
                {
                    ans++;
                    vis[x][y]=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
