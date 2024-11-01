#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define int long long
using namespace std;
const int N = 1e3 + 10;
int dx[4] = {0 , 1 , 0 , -1};
int dy[4] = {1 , 0 , -1 , 0};
char a[N][N];
bool vis[N][N];
int n , m , k;
int x0 , y0 , d0;
bool check(int x , int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        return 0;
    }
    if (a[x][y] == 'x')
    {
        return 0;
    }
    return 1;
}
void calc()
{
    memset(a , 0 , sizeof a);
    memset(vis , 0 , sizeof vis);
    cin >> n >> m >> k;
    cin >> x0 >> y0 >> d0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];
        }
    }
    vis[x0][y0] = 1;
    int x = x0 , y = y0;
    while (k--)
    {
        int nx = x + dx[d0];
        int ny = y + dy[d0];
        if (check(nx , ny))
        {
            x = nx;
            y = ny;
            vis[x][y] = 1;
        }
        else
        {
            d0 = (d0 + 1) % 4;
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
//            cout << vis[i][j] << " ";
            if (vis[i][j])
            {
                ans++;
            }
        }
//        cout << endl;
    }
    cout << ans << endl;
}
signed main()
{

    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);

    int t;
    cin >> t;
    while (t--)
    {
        calc();
    }
    return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....

*/
