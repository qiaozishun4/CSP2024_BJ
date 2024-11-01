#include<iostream>
using namespace std;

int T, n, m, k, x0, y0, d;
char ditu[1005][1005];
bool fangwen[1005][1005] = {0};

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &n, &m, &k);
        scanf("%d %d %d", &x0, &y0, &d);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m ;j++)
            {
                scanf("%c", &ditu[i][j]);
                fangwen[i][j] = 0;
            }
        }

        int nx = x0, ny = y0;
        while(1)
        {
            if(k == 0) break;
            if(d == 0) ny += 1;
            else if(d == 1) nx += 1;
            else if(d == 2) ny -= 1;
            else if(d == 3) nx -= 1;

            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && ditu[nx][ny] == '.')
            {
                fangwen[nx][ny] = 1;

                x0 = nx;
                y0 = ny;
                k--;
            }
            else
            {
                d = (d + 1) % 4;
                nx = x0;
                ny = y0;
                k--;
            }


        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++) if(fangwen[i][j]) cnt++;
        }
        printf("%d\n", cnt + 1);
    }
    return 0;
}
