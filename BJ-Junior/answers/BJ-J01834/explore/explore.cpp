#include<bits/stdc++.h>
using namespace std;
int t,a[1010][1010],k,dd,xx,yy,n,m,v[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>xx>>yy>>dd;
        int x=xx,y=yy,d=dd;
        char c;
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        v[xx][yy]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                if(c=='.')
                {
                    a[i][j]=0;
                }
                else if(c=='x')
                {
                    a[i][j]=1;
                }
            }
        }
        for(int op=1;op<=k;op++)
        {
            if(x+dx[d]>=1&&x+dx[d]<=n&&y+dy[d]>=1&&y+dy[d]<=m&&a[x+dx[d]][y+dy[d]]==0)
            {
                x+=dx[d];
                y+=dy[d];
                v[x][y]=1;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                ans+=v[i][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
