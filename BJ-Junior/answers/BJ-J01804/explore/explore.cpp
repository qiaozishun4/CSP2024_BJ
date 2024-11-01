#include <iostream>


int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int T;
    std::cin >> T;

    for (int ttt = 1; ttt <= T; ttt++)
    {
        int n, m, k;
        int x, y, d;
        std::cin >> n >> m >> k;
        std::cin >> x >> y >> d;

        bool map[2001][2001] = {false};
        bool foot[2001][2001] = {false};
        int answer = 1;

        foot[x][y] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char type;
                std::cin >> type;
                if (type == '.') map[i][j] = false;
                else map[i][j] = true;
            }
        }

        for (int i = 1; i <= k; i++)
        {
            int newx = x;
            int newy = y;

            if (d == 0) newy++;
            else if (d == 1) newx++;
            else if (d == 2) newy--;
            else newx--;

            if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && !map[newx][newy])
            {
                x = newx;
                y = newy;
                if (foot[newx][newy]) continue;
                else
                {
                    foot[x][y] = true;
                    answer++;
                }
            }
            else
            {
                d = (d + 1) % 4;
            }
        }

        std::cout << answer << std::endl;
    }

    return 0;
}
