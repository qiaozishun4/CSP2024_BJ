#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int dx[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char plan[1005][1005];

inline bool check(int x, int y)
{
	if(1 <= x && x <= n && 1 <= y && y <= m && plan[x][y] != 'x') return true;
	return false;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        memset(plan, '\0', sizeof(plan));
        int x, y, d, cnt = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> plan[i][j];
            }
        }
        while(k--)
        {
            // cout << x << ' ' << y << ' ' << d << ';';
            if(plan[x][y] == '.')
            {
                cnt++;
                plan[x][y] = ',';
            }
            int nx = x + dx[d][0], ny = y + dx[d][1];
            // cout << nx << ' ' << ny << endl;
            if(check(nx, ny))
            {
                x = nx;
                y = ny;
            }
            else d = (d + 1) % 4;
        }
        if(plan[x][y] == '.')
        {
            cnt++;
            plan[x][y] = ',';
        }
        cout << cnt << endl;
    }
    return 0;
}
