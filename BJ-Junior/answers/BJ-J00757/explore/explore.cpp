#include <iostream>

using namespace std;

bool map[1000][1000];
bool che[1000][1000];

int x, y, d;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T, n, m, k, ans, nex = 0, ney = 0;
    char temp;
    cin >> T;
    for (int z = 0; z < T; z++)
    {
        cin >> n >> m >> k >> x >> y >> d;
        x--;
        y--;
        ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> temp;
                if (temp == 'x')
                {
                    map[i][j] = true;
                }
            }
        }
        for (int i = 0; i < k; i++)
        {
            che[x][y] = true;
            nex = x + dx[d];
            ney = y + dy[d];
            if (nex >= 0 && nex < n && ney >= 0 && ney < m && !map[nex][ney])
            {
                x = nex;
                y = ney;
                if (!che[x][y])
                {
                    ans++;
                    che[x][y] = true;
                }
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                map[i][j] = false;
                che[i][j] = false;
            }
        }
    }
    return 0;
}
