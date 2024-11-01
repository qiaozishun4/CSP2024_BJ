#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
char a[N][N];
bool dis[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int cnt = 0;
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
            }
        }
        while(k--)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != 'x')
            {
                cnt++;
                dis[nx][ny] = 1;
                x = nx;
                y = ny;
            }
            else d = (d + 1) % 4;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
