#include <fstream>
using namespace std;

char mp[1001][1001];
bool vis[1001][1001][4];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ifstream fin("explore.in");
    ofstream fout("explore.out");

    int t;
    fin >> t;
    while (t--)
    {
        int n, m, k, x, y, d;
        fin >> n >> m >> k >> x >> y >> d;
        x--;
        y--;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                fin >> mp[i][j];
                vis[i][j][0] = false;
                vis[i][j][1] = false;
                vis[i][j][2] = false;
                vis[i][j][3] = false;
            }
        }

        vis[x][y][d] = true;
        for (int i = 0; i < k; i++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= n || nx < 0 || ny >= m || ny < 0 || mp[nx][ny] == 'x')
            {
                d = (d + 1) % 4;
            }
            else
            {
                x = nx;
                y = ny;
            }
            
            if (vis[x][y][d])
            {
                break;
            }
            else
            {
                vis[x][y][d] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j][0] || vis[i][j][1] || vis[i][j][2] || vis[i][j][3])
                {
                    ans++;
                }
            }
        }
        fout << ans << endl;
    }
}