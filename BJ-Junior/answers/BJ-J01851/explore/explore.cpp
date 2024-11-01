#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e3, M = 1e3, DX[] = { 0, 1, 0, -1 }, DY[] = { 1, 0, -1, 0 };

void solve_test()
{
    int n, m, k, x, y, hd;
    scanf("%d %d %d %d %d %d", &n, &m, &k, &x, &y, &hd);

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    char grid[N + 5][M + 5];
    vis[--x][--y] = true;

    for (int i = 0; i < n; ++i)
        scanf("%s", grid[i]);

    while (k-- > 0) {
        int nx = x + DX[hd], ny = y + DY[hd];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
            x = nx;
            y = ny;
        } else
            hd = (hd + 1) % 4;

        vis[x][y] = true;
    }

    int cnt = 0;

    for (const auto& row : vis)
        cnt += count(row.begin(), row.end(), true);

    printf("%d\n", cnt);
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t-- > 0)
        solve_test();

    fclose(stdin);
    fclose(stdout);
    return 0;
}