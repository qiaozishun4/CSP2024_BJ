#include<bits/stdc++.h>
using namespace std;
int n, m;
char a[1005][1005];
int h = 0;
int vis[1005][1005];
bool chicken(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == '.';
}
void dfs(int x, int y, int k, int d){
    if(!vis[x][y])
        h++;
    vis[x][y] = h;
    if(k == 0)
    {
        return;
    }
    bool flag = 0;
    while(k)
    {
        if(d == 0)
        {
            if(chicken(x, y + 1))
            {
                k--;
                dfs(x, y + 1, k, d);
                break;

            }
            else
            {
                k--;
                d = (d + 1) % 4;
                flag = 1;
            }
        }
        else if(d == 1)
        {
            if(chicken(x + 1, y))
            {
                k--;
                dfs(x + 1, y, k, d);
                break;
            }
            else
            {
                k--;
                d = (d + 1) % 4;
                flag = 1;
            }
        }
        else if(d == 2)
        {
            if(chicken(x, y - 1))
            {
                k--;
                dfs(x, y - 1, k, d);
                break;
            }
            else
            {
                k--;
                d = (d + 1) % 4;
                flag = 1;
            }
        }
        else if(d == 3)
        {
            if(chicken(x - 1, y))
            {
                k--;
                dfs(x - 1, y, k, d);
                break;
            }
            else
            {
                k--;
                d = (d + 1) % 4;
                flag = 1;
            }
        }
    }
    return;
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        cin >> n >> m >> k;
        int x, y;
        int d;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        dfs(x, y, k, d);
        cout << h;
        h = 0;
        if(t != 0)
            cout << endl;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                vis[i][j] = 0;
            }
        }
    }
    return 0;
}