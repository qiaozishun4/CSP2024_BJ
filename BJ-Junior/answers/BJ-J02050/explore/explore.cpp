#include <bits/stdc++.h>
using namespace std;
char a[1003][1003];
long long n , m , k;
bool check(long long x , long long y)
{
    if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 'x') return true;
    return false;
}
void dfs(long long x , long long y , long long d)
{
    if(k == -1) return;
    if(!check(x , y))
    {
        if(d == 0)
        {
            y--;
        }
        else if(d == 1)
        {
            x--;
        }
        else if(d == 2)
        {
            y++;
        }
        else
        {
            x++;
        }
        d = (d + 1) % 4;
    }
        a[x][y] = '#';
        if(d == 0)
        {
            y++;
        }
        else if(d == 1)
        {
            x++;
        }
        else if(d == 2)
        {
            y--;
        }
        else
        {
            x--;
        }
    k--;
    dfs(x , y , d);
}
void solve()
{
    memset(a , 0 , sizeof(a));
    cin >> n >> m >> k;
    long long x , y , d;
    cin >> x >> y >> d;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cin >> a[i][j];
        }
    }
    dfs(x , y , d);
    long long ans = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(a[i][j] == '#')
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);
    int T;
    cin >> T;
    for(int i = 1;i <= T;i++) solve();
    return 0;
}