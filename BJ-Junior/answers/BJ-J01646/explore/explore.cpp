#include<bits/stdc++.h>
using namespace std;
int n,m,k,sx,sy,sd;
char a[1007][1007];
bool g[1007][1007];
void ffs(int x,int y,int p,int d)
{
    //cout<<x<<" "<<y<<" "<<p<<endl;
    g[x][y]=1;
    if(p==0)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(g[i][j]==1)
                {
                    cnt++;
                    //cout<<i<<" "<<j<<endl;
                }
                g[i][j]=0;
                a[i][j]='x';
            }
        }
        cout<<cnt<<endl;
        return;
    }
    if(d==0)
    {
        if(a[x][y+1]=='.')
        {
            ffs(x,y+1,p-1,d);
        }
        else
        {
            ffs(x,y,p-1,(d+1)%4);
        }
    }
    else if(d==1)
    {
        if(a[x+1][y]=='.')
        {
            ffs(x+1,y,p-1,d);
        }
        else
        {
            ffs(x,y,p-1,(d+1)%4);
        }
    }
    else if(d==2)
    {
        if(a[x][y-1]=='.')
        {
            ffs(x,y-1,p-1,d);
        }
        else
        {
            ffs(x,y,p-1,(d+1)%4);
        }
    }
    else if(d==3)
    {
        if(a[x-1][y]=='.')
        {
            ffs(x-1,y,p-1,d);
        }
        else
        {
            ffs(x,y,p-1,(d+1)%4);
        }
    }
    return;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        cin>>sx>>sy>>sd;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        ffs(sx,sy,k,sd);
    }
    return 0;
}
