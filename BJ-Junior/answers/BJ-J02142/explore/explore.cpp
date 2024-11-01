#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool b[1005][1005]={};
int ex(int n,int m,int k,int x,int y,int d,int ans,int x1,int y1)
{
    b[x1][y1]=1;
    if(k==0)
    {
        return ans;
    }
    if(x<=n && x>=1 && y<=m && y>=1)
    {
        if(d==0)
        {
            if(y+1<=m && a[x][y+1]=='.')
            {
                if(b[x][y+1]==0)
                {
                    ans=ans+1;
                }
                b[x][y+1]=1;
                ex(n,m,k-1,x,y+1,d,ans,x1,y1);
            }
            else
            {
                ex(n,m,k-1,x,y,(d+1)%4,ans,x1,y1);
            }
        }
        else if(d==1)
        {
            if(x+1<=n && a[x+1][y]=='.')
            {
                if(b[x+1][y]==0)
                {
                    ans=ans+1;
                }
                b[x+1][y]=1;
                ex(n,m,k-1,x+1,y,d,ans,x1,y1);
            }
            else
            {
                ex(n,m,k-1,x,y,(d+1)%4,ans,x1,y1);
            }
        }
        else if(d==2)
        {
            if(y-1>=1 && a[x][y-1]=='.')
            {
                if(b[x][y-1]==0)
                {
                    ans=ans+1;
                }
                b[x][y-1]=1;
                ex(n,m,k-1,x,y-1,d,ans,x1,y1);
            }
            else
            {
                ex(n,m,k-1,x,y,(d+1)%4,ans,x1,y1);
            }
        }
        else if(d==3)
        {
            if(x-1>=1 && a[x-1][y]=='.')
            {
                if(b[x-1][y]==0)
                {
                    ans=ans+1;
                }
                b[x-1][y]=1;
                ex(n,m,k-1,x-1,y,d,ans,x1,y1);
            }
            else
            {
                ex(n,m,k-1,x,y,(d+1)%4,ans,x1,y1);
            }
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int n,m,k,x,y,d;
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=1;i<=n;i++)
    {
        for(int i=1;i<=m;i++)
        {
           cin>>a[n][m];
        }
    }
    cout<<ex(n,m,k,x,y,d,1,x,y);
    }
return 0;
}
