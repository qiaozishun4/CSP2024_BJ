#include<bits/stdc++.h>
using namespace std;
long long n,m,k,t,x,y,d,ans=1;
int a[1005][1005];
char o;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%lld",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&k,&x,&y,&d);
        for(int j=1;j<=n;j++)
        {
            for(int p=1;p<=m;p++)
            {
                cin>>o;
                if(o=='.')
                    a[j][p]=1;
                if(o=='x')
                    a[j][p]=0;
            }
        }
        a[x][y]=2;
        for(int j=1;j<=k;j++)
        {
            if(d==0)
            {
                if(a[x][y+1]!=0)
                {
                    y++;
                    if(a[x][y]==1)
                    {
                        ans++;
                        a[x][y]=2;
                    }
                    continue;
                }
            }
            if(d==1)
            {
                if(a[x+1][y]!=0)
                {
                    x++;
                    if(a[x][y]==1)
                    {
                        ans++;
                        a[x][y]=2;
                    }
                    continue;
                }
            }
            if(d==2)
            {
                if(a[x][y-1]!=0)
                {
                    y--;
                    if(a[x][y]==1)
                    {
                        ans++;
                        a[x][y]=2;
                    }
                    continue;
                }
            }
            if(d==3)
            {
                if(a[x-1][y]!=0)
                {
                    x--;
                    if(a[x][y]==1)
                    {
                        ans++;
                        a[x][y]=2;
                    }
                    continue;
                }
            }
            d=(d+1)%4;
        }
        cout<<ans<<endl;
        ans=1;
        memset(a,0,sizeof(a));
    }
    return 0;
}