#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
int T,n,m,k;
bool f[maxn][maxn],q[maxn][maxn];//1kong,0zhang;
char ch;
bool xfind(int x,int y,int d)
{
    if(d==0)
    {
        if(y+1>m)
            return 0;
        else
            return f[x][y+1];
    }
    if(d==1)
    {
        if(x+1>n)
            return 0;
        else
            return f[x+1][y];
    }
    if(d==2)
    {
        if(y-1<1)
            return 0;
        else
            return f[x][y-1];
    }
    if(d==3)
    {
        if(x-1<1)
            return 0;
        else
            return f[x-1][y];
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    for(int o=0;o<T;++o)
    {
        int x,y,d;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        int ans=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                q[i][j]=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                cin>>ch;
                if(ch=='.')
                    f[i][j]=1;
                else
                    f[i][j]=0;
            }
        for(int i=1;i<=k;++i)
        {
            if(q[x][y]==0)
            {
                ++ans;
                q[x][y]=1;
            }
            if(xfind(x,y,d))
            {
                if(d==0)
                {
                    y+=1;
                }
                else if(d==1)
                {
                    x+=1;
                }
                else if(d==2)
                {
                    y-=1;
                }
                else if(d==3)
                {
                    x-=1;
                }
            }
            else
            {
                d=(d+1)%4;
            }
        }
        if(q[x][y]==0)
            ++ans;
        printf("%d\n",ans);
    }

    return 0;
}
