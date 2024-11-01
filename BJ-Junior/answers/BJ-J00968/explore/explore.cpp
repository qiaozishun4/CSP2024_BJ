#include <bits/stdc++.h>
using namespace std;
int T;
long long k;
int x,y;
long long n,m;
bool f[10003][10003];
char c[1003][1003];
int d;
int num=0,ans=1;
void dfs(int x,int y,int d)
{
    bool fl=1;
    if (num==k)
    {
        cout<<ans<<endl;
    }
    else
    {
        if(d==0)
        {
            if (c[x][y+1]=='.')
            {
                num++;
                if (f[x][y+1]==0)
                {
                    ans++;
                    f[x][y+1]=1;
                }
                dfs(x,y+1,0);
                fl=0;
            }
        }
        if(d==1)
        {
            if (c[x+1][y]=='.')
            {
                num++;
                if (f[x+1][y]==0)
                {
                    ans++;
                    f[x+1][y]=1;
                }
                dfs(x+1,y,1);
                fl=0;
            }
        }
        if(d==2)
        {
            if (c[x][y-1]=='.')
            {
                num++;
                if (f[x][y-1]==0)
                {
                    ans++;
                    f[x][y-1]=1;
                }
                dfs(x,y-1,2);
                fl=0;
            }
        }
        if(d==3)
        {
            if (c[x-1][y]=='.')
            {
                num++;
                if (f[x-1][y]==0)
                {
                    ans++;
                    f[x-1][y]=1;
                }
                dfs(x-1,y,3);
                fl=0;
            }
        }

            if (fl)//nan
            {
                num++;
                dfs(x,y,(d+1)%4);
            }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for (int i=1;i<=T;i++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        memset(c,0,sizeof(c));
        memset(f,0,sizeof(f));
        for (int j=1;j<=n;j++)
        {
            for (int p=1;p<=m;p++)
            {
                cin>>c[j][p];
            }
        }
        dfs(x,y,d);
    }
    return 0;
}
