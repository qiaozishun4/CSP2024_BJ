#include <bits/stdc++.h>
#define int long long
using namespace std;

int t;
char a[1005][1005];
bool flag[1005][1005];
signed main()
{
    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);
    cin >> t;
    while(t--)
    {
        int n , m , k , x , y , d;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        memset(flag , 0 , sizeof flag);
        flag[x][y] = 1;
        while(k--)
        {
            int nx = x , ny = y;
            if(d == 0) ny++;
            if(d == 1) nx++;
            if(d == 2) ny--;
            if(d == 3) nx--;
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.') {flag[nx][ny] = 1;x = nx;y = ny;continue;}
            else {d = (d + 1) % 4;continue;}
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(flag[i][j]) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
