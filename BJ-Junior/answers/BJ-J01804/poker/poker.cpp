#include <iostream>

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n;
    std::cin >> n;

    bool map[500][500];
    int answer=52;

    for (int i = 1; i <= n; i++)
    {
        char poker[2];
        std::cin >> poker[0] >> poker[1];

        int x, y;

        x = char(poker[0]);
        y = char(poker[1]);

        if (map[x][y]) continue;
        else
        {
            map[x][y] = true;
            answer--;
        }
    }

    std::cout << answer;

    return 0;
}
