#include <bits/stdc++.h>
#define int long long
using namespace std;
char a[1001][1001];
bool check[1001][1001]={0};
void lesson()
{
    memset(check,0,sizeof(check));
    memset(a,0,sizeof(a));
    int n,m,k;
    cin>>n>>m>>k;
    int x,y,d;
    cin>>x>>y>>d;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=1;i<=k;i++)
    {
        if(d==0)//东
        {
            if(a[x+1][y]=='.'&&x+1>0
               &&y>0&&x+1<=n&&y<=m)
               {
                   if(!check[x+1][y])
                   {
                       cnt++;
                       check[x+1][y]=1;
                   }
                    x=x+1;
               }
            else
                d=(d+1)%4;
        }
        else if(d==1)
        {
            if(a[x][y+1]=='.'&&x>0
               &&y+1>0&&x<=n&&y+1<=m)
               {
                   if(!check[x][y+1])
                   {
                       cnt++;
                       check[x][y+1]=1;
                   }
                    y=y+1;
               }
            else
                d=(d+1)%4;
        }
        else if(d==2)
        {
            if(a[x-1][y]=='.'&&x-1>0
               &&y>0&&x-1<=n&&y<=m)
               {
                   if(!check[x-1][y])
                   {
                       cnt++;
                       check[x-1][y]=1;
                   }
                   x=x-1;
               }
            else
                d=(d+1)%4;
        }
        else
        {
            if(a[x][y-1]=='.'&&x>0
               &&y-1>0&&x<=n&&y-1<=m)
               {
                   if(!check[x][y-1])
                   {
                       cnt++;
                       check[x][y-1]=1;
                   }
                   y=y-1;
               }
            else
                d=(d+1)%4;
        }
    }
    cout<<cnt<<endl;
}
signed main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        lesson();
    }
    return 0;
}
