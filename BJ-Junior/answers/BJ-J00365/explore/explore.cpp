#include <bits/stdc++.h>
using namespace std;
char mp[1005][1005];
int vis[1005][1005], cnt = 0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool f = false;
bool check( int x, int y, int n, int m )
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
void dfs( int xs, int ys, int d0, int n, int m, int k )
{
    if( k <= 0 || f )
    {
//        cout << "    2" << endl;
        f = true;
        return;
    }
    int i, nx = 0, ny = 0;
    i = d0;
    for( ; i < 4; i++ )
    {
//        cout << k << i << endl;
//        cout << xs << " " << ys << endl;
        nx = xs+dx[i], ny = ys+dy[i], k--;
        if( k < 0 )
            break;
//        cout << nx<< " " << ny << endl;
        if( check( nx, ny, n, m ) && mp[nx][ny] == '.' )
        {
//            cout << " 11" << endl;
            vis[nx][ny] = 1;
            //cnt++;
            dfs( nx, ny, i, n, m, k );
            break;
        }
        nx -= dx[i], ny -= dy[i];
        if( k && i == 3 )
        {
//            cout << "     1" << endl;
            dfs( xs, ys, 0, n, m, k );
            break;
        }
    }
}
int main()
{
    freopen( "explore.in", "r", stdin );
    freopen( "explore.out", "w", stdout );

    long long n, m, k, i, j, T, xs, ys, d0;
    cin >> T;
    while (T--)
    {
        f = false, cnt = 0;
        cin >> n >> m >> k;
        cin >> xs >> ys >> d0;
        for( i = 1; i <= n; i++ )
        {
            for( j = 1; j <= m; j++ )
            {
                cin >> mp[i][j];
                vis[i][j] = 0;
            }
        }
        vis[xs][ys] = 1;
        dfs( xs, ys, d0%4, n, m, k );
        for( i = 1; i <= n; i++ )
        {
            for( j = 1; j <= m; j++ )
            {
//                cout << vis[i][j] <<" ";
                if( vis[i][j] )
                    cnt++;
            }
//            cout << endl;
        }
        cout << cnt << endl;
//        cout << endl;
   }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
