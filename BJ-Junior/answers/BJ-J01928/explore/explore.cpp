#include<iostream>
using namespace std;
int main(int argc, char**argv)
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    int t1;
    t1=t;
    int w[t+5]={0};
    char c[1005][1005];
    int a[1005][1005]={0};
    int n,m,x,y;
    int bu,d;
    int ans=0;
    while(t>0)
    {
        ans=0;
        t--;
        ans=0;
        cin>>n>>m;
        cin>>bu;
        cin>>x>>y;
        cin>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                a[i][j]=0;
                cin>>c[i][j];
            }
        }
        a[x][y]=1;
        for(int i=1;i<=bu;i++)
        {
            if(d==0)
            {
                if(y+1<=m&&c[x][y+1]=='.')
                {
                    y++;
                    a[x][y]=1;
                    continue;
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }

            }
            if(d==1)
            {
                if(x+1<=n&&c[x+1][y]=='.')
                {
                    x++;
                    a[x][y]=1;
                    continue;
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }

            }
            if(d==2)
            {
                if(y-1>=1&&c[x][y-1]=='.')
                {
                    y--;
                    a[x][y]=1;
                    continue;
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }

            }
            if(d==3)
            {
                if(x-1>=1&&c[x-1][y]=='.')
                {
                    x--;
                    a[x][y]=1;
                    continue;
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }
            }
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]==1)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
