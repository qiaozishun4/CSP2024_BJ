#include<bits/stdc++.h>
using namespace std;
long long n,m,k,d,xs,ys,ans,vis[1005][1005];
char maze[1005][1005];
int movee[4][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
bool check(long long x,long long y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m);
}
void dfs(long long x,long long y,long long f,long long step)
{
    //cout<<x<<","<<y<<" "<<f<<" "<<step<<":"<<ans<<endl;
    if(step >= k) return ;
    long long dx = x+movee[f][0],dy = y+movee[f][1];
    if(check(dx,dy) && maze[dx][dy] == '.')
    {
        if(vis[dx][dy] == 0)
        {
            vis[dx][dy] = 1;
            ans++;
        }
        dfs(dx,dy,f,step+1);
        return ;
    }
    dfs(x,y,(f+1)%4,step+1);
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        ans = 1;
        cin>>n>>m>>k>>xs>>ys>>d;
        for(long long i = 1;i <= n;i++)
        {
            for(long long j = 1;j <= m;j++)
            {
                cin>>maze[i][j];
                vis[i][j] = 0;
            }
        }
        vis[xs][ys] = 1;
        dfs(xs,ys,d,0);
        //cout<<"ans:";
        cout<<ans<<endl;
    }
}
/*#include<bits/stdc++.h>
using namespace std;
long long n,m,k,d,xs,ys,ans,vis[1005][1005],oo,sum = 0;
char maze[1005][1005];
int movee[4][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
bool check(long long x,long long y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m);
}
long long maxx(long long a,long long b)
{
    if(a > b) return a;
    return b;
}
void count_(int x,int y,int cnt)
{
    sum = maxx(sum,cnt);
    for(int i = 0;i < 4;i++)
    {
        int dx = x+movee[i][0],dy = y+movee[i][1];
        if(check(dx,dy) && !vis[dx][dy] && maze[dx][dy] == '.')
        {
            vis[dx][dy] = 1;
            count_(dx,dy,cnt+1);
            vis[dx][dy] = 0;
        }
    }
    sum = maxx(sum,cnt);
}
void dfs(long long x,long long y,long long f,long long step)
{
    //cout<<x<<","<<y<<" "<<f<<" "<<step<<":"<<ans<<endl;
    if(step >= k) return ;
    long long dx = x+movee[f][0],dy = y+movee[f][1];
    if(check(dx,dy) && maze[dx][dy] == '.' && oo < sum)
    {
        if(vis[dx][dy] == 0)
        {
            vis[dx][dy] = 1;
            oo++;
            ans++;
        }
        dfs(dx,dy,f,step+1);
        return ;
    }
    dfs(x,y,(f+1)%4,step+1);
}
int main()
{
    freopen("explore5.in","r",stdin);
    freopen("explore5.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        ans = 1;
        cin>>n>>m>>k>>xs>>ys>>d;
        for(long long i = 1;i <= n;i++)
        {
            for(long long j = 1;j <= m;j++)
            {
                cin>>maze[i][j];
                vis[i][j] = 0;
            }
        }
        vis[xs][ys] = 1;
        count_(xs,ys,1);
        sum++;
        memset(vis,0,sizeof(vis));
        dfs(xs,ys,d,0);
        //cout<<"ans:";
        cout<<ans<<endl;
    }
}*/