#include<bits/stdc++.h>
using namespace std;
int t , n , m , k , x , y , d , ans;
char mp[1005][1005];
int main()
{
    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 0 ; i <= n + 1 ; i++)
        {
            for(int j = 0 ; j <= m + 1 ; j++)
            {
                mp[i][j] = 'x';
            }
        }
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                cin >> mp[i][j];
            }
        }
        mp[x][y] = '*';
        while(k--)
        {
            if(d == 0)
            {
                if(mp[x][y + 1] != 'x')
                {
                    y++;
                    mp[x][y] = '*';
                    continue;
                }
                d++;
                continue;
            }
            if(d == 1)
            {
                if(mp[x + 1][y] != 'x')
                {
                    x++;
                    mp[x][y] = '*';
                    continue;
                }
                d++;
                continue;
            }
            if(d == 2)
            {
                if(mp[x][y - 1] != 'x')
                {
                    y--;
                    mp[x][y] = '*';
                    continue;
                }
                d++;
                continue;
            }
            if(mp[x - 1][y] != 'x')
            {
                x--;
                mp[x][y] = '*';
                continue;
            }
            d = 0;
        }
        ans = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                if(mp[i][j] == '*')
                {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
