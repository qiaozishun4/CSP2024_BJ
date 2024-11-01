#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+5;
int T,n,m,k,x,y,d;
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int cnt;

void dfs(int step)
{
    if(step > k)
    {
        cout << cnt << endl;
        return;
    }
    if(d == 0 && x <= n && y+1 <= m && x >= 1 && y+1 >= 1 && a[x][y+1] == '.')
    {
        y += 1;
        if(vis[x][y] == false)
        {
            cnt++;
            vis[x][y] = true;
        }
        dfs(step+1);
        return;
    }
    else if(d == 1 && x+1 <= n && y <= m && x+1 >= 1 && y >= 1 && a[x+1][y] == '.')
    {
        x += 1;
        if(vis[x][y] == false)
        {
            cnt++;
            vis[x][y] = true;
        }
        dfs(step+1);
        return;
    }
    else if(d == 2 && x <= n && y-1 <= m && x >= 1 && y-1 >= 1 && a[x][y-1] == '.')
    {
        y -= 1;
        if(vis[x][y] == false)
        {
            cnt++;
            vis[x][y] = true;
        }
        dfs(step+1);
        return;
    }
    else if(d == 3 && x-1 <= n && y <= m && x-1 >= 1 && y >= 1 && a[x-1][y] == '.')
    {
        x -= 1;
        if(vis[x][y] == false)
        {
            cnt++;
            vis[x][y] = true;
        }
        dfs(step+1);
        return;
    }
    d = (d+1)%4;
    dfs(step+1);
    return;
}


int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    for(int i = 1 ; i <= T ; i++)
    {
        cnt = 1;
        memset(vis,false,sizeof(vis));
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        vis[x][y] = true;
        for(int j = 1 ; j <= n ; j++)
        {
            string s;
            cin >> s;
            for(int k = 0 ; k < m ; k++)
            {
                a[j][k+1] = s[k];
            }
        }
        dfs(1);
    }
    return 0;
}