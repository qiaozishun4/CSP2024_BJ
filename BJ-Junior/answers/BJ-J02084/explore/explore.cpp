#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,d,t;
char e;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        cin>>n>>m>>k>>x>>y>>d;
        bool a[1001][1001]={},b[1001][1001]={};
        b[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>e;
                if(e=='x')
                {
                    a[i][j]=1;
                }
            }
        }
        for(int i=1;i<=k;i++)
        {
            if(d==0)
            {
                if(y+1<=m&&a[x][y+1]==0)
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
                if(x+1<=n&&a[x+1][y]==0)
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
                if(y-1>=1&&a[x][y-1]==0)
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
                if(x-1>=1&&a[x-1][y]==0)
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
        long long x=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(b[i][j])
                {
                    x++;
                }
            }
        }
        cout<<x<<endl;
    }
    return 0;
}