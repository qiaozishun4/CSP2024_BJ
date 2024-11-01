#include <iostream>
using namespace std;
int t,b[1005][1005],n,m,k,x,y,d,ans;
char a[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        b[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        ans=0;
        for(int i=1;i<=k;i++)
        {
            if(d==0)
            {
                if(y+1<=m&&a[x][y+1]=='.')
                {
                    y++;
                    b[x][y]=1;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==1)
            {
                if(x+1<=n&&a[x+1][y]=='.')
                {
                    x++;
                    b[x][y]=1;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==2)
            {
                if(y-1>=1&&a[x][y-1]=='.')
                {
                    y--;
                    b[x][y]=1;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==3)
            {
                if(x-1>=1&&a[x-1][y]=='.')
                {
                    x--;
                    b[x][y]=1;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                ans+=b[i][j];
                b[i][j]=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
