#include <bits/stdc++.h>
using namespace std;

int n , m , k;
char a[1010][1010];
bool vis[1010][1010];
int dx[] = {0 , 1 , 0 , -1} , dy[] = {1 , 0 , -1 , 0};

bool check (int x , int y)
{
    return (x < 1 || x > n || y < 1 || y > m || a[x][y] == 'x');
}

void dfs (int x , int y , int d , int step)
{
    if(step >= k) return ;
        
    while(1)
    {
        int nx = x + dx[d] , ny = y + dy[d];
        step++;
        // cout << "方向为： " << d << "步数为： " << step << endl;
        if (!check(nx , ny))
        {
            vis[nx][ny] = true;
            // cout << nx << " " << ny << " " << d << endl;
            dfs (nx , ny , d , step);
            break ;
        }
        if (step == k) return ;
        d = (d + 1) % 4;
    }
}

int main()
{
    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);
    int T;
    cin >> T;
    while(T--)
    {
        memset(vis , false , sizeof vis);
        int x , y , d;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                cin >> a[i][j];
        
        dfs (x , y , d , 0);
        
        int ans = 0;
        vis[x][y] = true;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                if(vis[i][j]) ans++;
        cout << ans << endl;
        // cout << endl;
        // cout << endl;
    }
    return 0;
}