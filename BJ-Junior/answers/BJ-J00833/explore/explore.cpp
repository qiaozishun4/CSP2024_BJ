#include <bits/stdc++.h>
using namespace std ;

int n , m ;
int a[1100][1100] , vis[1100][1100] ;
int x , y , k , d;
int dx[5] = {0 , 1 , 0 , -1} ;
int dy[5] = {1 , 0 , -1 , 0} ;

bool check()
{
    int nx = x + dx[d] , ny = y + dy[d] ;
    if(nx > n || ny > m || nx < 1 || ny < 1 || a[nx][ny] == 1)
        return 0 ;
    return 1 ;
}
int main()
{
    freopen("explore.in" , "r" , stdin) ;
    freopen("explore.out" , "w" , stdout) ;
    int t ;
    cin >> t ;
    while(t--)
    {
        cin >> n >> m >> k ;
        cin >> x >> y >> d;
        for(int i = 1 ; i <= n ; i ++)
        {
            for(int j = 1 ; j <= m ; j ++)
            {
                char c ;
                cin >> c;
                if(c == '.') a[i][j] = 0 ;
                else a[i][j] = 1 ;
                vis[i][j] = 0 ;
            }
        }
        // int cnt = 1;
        bool flag = 0 ;
        vis[x][y] = 1;
        while(k --)
        {
            if(check())
            {
                x += dx[d] ;
                y += dy[d] ;
                vis[x][y] = 1;
            }
            else if(!check() && vis[x + dx[d]][y + dy[d]])
            {
                break ;
            }
            else 
            {
                d = (d + 1) % 4; 
            }
        }
        int cnt = 0;
        for(int i = 1 ; i <= n ; i ++)
        {
            for(int j = 1 ; j <= m ; j ++)
            {
                cnt += (vis[i][j] == 1);
            }
        }
        cout << cnt << endl;
    }
    return 0 ; 
}