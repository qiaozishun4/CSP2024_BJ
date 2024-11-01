#include <bits/stdc++.h>
using namespace std;
int T;
int n,m,k;
int x,y,d;
char a[1005][1005];
bool vis[1005][1005];
int ans;
bool flag=false;
void dp(int x,int y,int d,int t,int s)
{
    if(t==0)
    {
        if(flag==false)
        {
            cout<<s<<endl;
            flag=true;
        }
        return ;
    }
    if(d==0)
    {
        if(y+1>m)dp(x,y,(d+1)%4,t-1,s);
        else if(a[x][y+1]=='x')dp(x,y,(d+1)%4,t-1,s);
        else if(a[x][y+1]=='.')
        {
            if(vis[x][y]==0)
            {
                dp(x,y+1,d,t-1,s+1);
                vis[x][y]=1;
            }
            else dp(x,y+1,d,t-1,s);
        }
    }
    if(d==1)
    {
        if(x+1>n)dp(x,y,(d+1)%4,t-1,s);
        else if(a[x+1][y]=='x')dp(x,y,(d+1)%4,t-1,s);
        else if(a[x+1][y]=='.')
        {
            if(vis[x][y]==0)
            {
                    dp(x+1,y,d,t-1,s+1);
                    vis[x][y]=1;
            }
            else dp(x+1,y,d,t-1,s);
        }
    }
    if(d==2)
    {
        if(y-1<=0)dp(x,y,(d+1)%4,t-1,s);
        else if(a[x][y-1]=='x')dp(x,y,(d+1)%4,t-1,s);
        else if(a[x][y-1]=='.')
        {
            if(vis[x][y]==0)
            {
                dp(x,y-1,d,t-1,s+1);
                vis[x][y]=1;
            }
            else dp(x,y-1,d,t-1,s);
        }
    }
    if(d==3)
    {
        if(x-1<=0)dp(x,y,(d+1)%4,t-1,s);
        else if(a[x-1][y]=='x')dp(x,y,(d+1)%4,t-1,s);
        else if(a[x-1][y]=='.')dp(x-1,y,d,t-1,s+1);
        {
            if(vis[x][y]==0)
            {
                dp(x-1,y,d,t-1,s+1);
                vis[x][y]=1;
            }
            else dp(x-1,y,d,t-1,s);
        }
    }

}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        flag=false;
        dp(x,y,d,k,1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
