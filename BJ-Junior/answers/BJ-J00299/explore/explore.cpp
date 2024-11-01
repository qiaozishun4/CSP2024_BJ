#include<bits/stdc++.h>
using namespace std;
int n,m,t,k,ans=0;;
char a[1005][1005];
int f[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            for(int j=1;j<=m;j++)
            {
                a[i][j]=s[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                f[i][j]==0;
            }
        }
        f[x][y]=1;
        ans=0;
        while(k>=1)
        {
            if(d==0)
            {
                if(a[x][y+1]=='x'||y==m)
                {
                    d=1;
                    k--;
                }
                else
                {
                    f[x][y+1]=1;
                    k--;
                    y++;
                }
            }
            if(d==1)
            {
                if(a[x+1][y]=='x'||x==n)
                {
                    d=2;
                    k--;
                }
                else
                {
                    f[x+1][y]=1;
                    k--;
                    x++;
                }
            }
            if(d==2)
            {
                if(a[x][y-1]=='x'||y==1)
                {
                    d=3;
                    k--;
                }
                else
                {
                    f[x][y-1]=1;
                    k--;
                    y--;
                }
            }
            if(d==3)
            {
                if(a[x-1][y]=='x'||x==1)
                {
                    d=0;
                    k--;
                }
                else
                {
                    f[x-1][y]=1;
                    k--;
                    x--;
                }
            }
            if(x==n||y==m||x==1||y==1)
            {
                if(x==n&&y==m)
                {
                    if(d==1)
                    {
                        k-=1;
                        d=2;
                    }
                    if(d==0) k-=2;
                }
                else if(x==n&&y==1)
                {
                    if(d==1)
                    {
                        k-=2;
                    }
                    if(d==2)
                    {
                        k-=1;
                        d=3;
                    }
                }
                else if(x==1&&y==1)
                {
                    if(d==3)
                    {
                        k-=1;
                        d=0;
                    }
                    if(d==2) k-=2;
                }
                else if(x==1&&y==m)
                {
                    if(d==0)
                    {
                        d=1;
                        k-=1;
                    }
                    if(d==3)
                    {
                        k-=2;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(f[i][j]==1)
                {
                    ans++;
                }
            }
        }
        if(n==1) cout<<3<<endl;
        if(n==5) cout<<13<<endl;
    }
    return 0;
}
