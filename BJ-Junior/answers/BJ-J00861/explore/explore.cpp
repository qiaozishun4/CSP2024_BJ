#include<iostream>
using namespace std;
int t, n, m, k, x, y, d, cnt = 1, tx, ty;
char mp[1005][1005];
bool went[1005][1005];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    for(int tot = 1; tot <= t; tot++)
    {
        cnt = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                went[i][j] = false;
            }
        }
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> mp[i][j];
            }
        }
        tx = x, ty = y;
        went[x][y] = true;
        for(int i = 1; i <= k; i++)
        {
            if(d == 0) ty = y + 1;    // east
            else if(d == 1) tx = x + 1;// south
            else if(d == 2) ty = y - 1;// west
            else tx = x - 1; //d0 == 3  // north
            if(mp[tx][ty] == '.')
            {
                x = tx;
                y = ty;
                if(went[x][y] == false) cnt++;
                went[x][y] = true;
            }
            else
            {
                d = (d + 1) % 4;
                tx = x;
                ty = y;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
