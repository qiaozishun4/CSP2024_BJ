#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,sx,sy,sd;
char s[1005][1005];
bool vis[1005][1005];
void dfs(long long x,long long y,long long d,long long res)
{
    if(res == 0) return;
    res--;
    long long a = x,b = y;
    if(d == 0) b++;
    if(d == 1) a++;
    if(d == 2) b--;
    if(d == 3) a--;
    if(a >= 1 && a <= n && b >= 1 && b <= m && s[a][b] == '.')
    {
        vis[a][b] = true;
        dfs(a,b,d,res);
    }
    else
    {
        d = (d + 1) % 4;
        dfs(x,y,d,res);
    }

}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        long long cnt = 0;
        cin>>n>>m>>k;
        cin>>sx>>sy>>sd;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin>>s[i][j];
            }
        }
        vis[sx][sy] = true;
        dfs(sx,sy,sd,k);
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(vis[i][j]) cnt++;
            }
        }
        cout<<cnt<<endl;
        memset(vis,0,sizeof vis);
    }
    return 0;
}

