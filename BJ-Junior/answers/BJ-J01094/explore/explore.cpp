#include<iostream>
using namespace std;
char c[1010][1010];
bool flag[1010][1010];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int x0, y0, d0;
        cin >> x0 >> y0 >> d0;
        int x = x0, y = y0, d = d0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                cin >> c[i][j];
        }
        int ans = 1;
        for(int i = 1; i <= k; i++)
        {
            if(d == 0)
            {
                if(c[x][y+1] != 'x' && x >= 1 && x <= n && y + 1 >= 1 && y + 1 <= m)
                {
                    y += 1;
                    if(flag[x][y] == 0)
                    {
                        ans++;
                        flag[x][y] = 1;
                    }
                }
                else
                {
                    d = (d + 1) % 4;
                    continue;
                }
            }
            if(d == 1)
            {
                if(c[x+1][y] != 'x' && x + 1 >= 1 && x + 1 <= n && y >= 1 && y <= m)
                {
                    x += 1;
                    if(flag[x][y] == 0)
                    {
                        ans++;
                        flag[x][y] = 1;
                    }
                }
                else
                {
                    d = (d + 1) % 4;
                    continue;
                }
            }
            if(d == 2)
            {
                if(c[x][y-1] != 'x' && x >= 1 && x <= n && y - 1 >= 1 && y - 1 <= m)
                {
                    y -= 1;
                    if(flag[x][y] == 0)
                    {
                        ans++;
                        flag[x][y] = 1;
                    }
                }
                else
                {
                    d = (d + 1) % 4;
                    continue;
                }
            }
            if(d == 3)
            {
                if(c[x-1][y] != 'x' && x - 1 >= 1 && x - 1 <= n && y >= 1 && y <= m)
                {
                    x -= 1;
                    if(flag[x][y] == 0)
                    {
                        ans++;
                        flag[x][y] = 1;
                    }
                }
                else
                {
                    d = (d + 1) % 4;
                    continue;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
