#include<bits/stdc++.h>
using namespace std;
int t;
char c[1005][1005];
bool f[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof(0));
        int n,m,k,x,y,d,sum;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
            }
        }
        for(int i=1;i<=k;i++)
        {
            if(!f[x][y])
            {
                f[x][y]=1;
                sum++;
            }
            int xx,yy;
            if(d==0)
            {
                xx=x;
                yy=y+1;
            }
            else if(d==1)
            {
                xx=x+1;
                yy=y;
            }
            else if(d==2)
            {
                xx=x;
                yy=y-1;
            }
            else
            {
                xx=x-1;
                yy=y;
            }
            if(xx<1||yy<1||xx>n||yy>m||c[xx][yy]=='x')
            {
                d=(d+1)%4;
                continue;
            }
            x=xx;
            y=yy;
        }
        if(!f[x][y])
        {
            f[x][y]=1;
            sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
