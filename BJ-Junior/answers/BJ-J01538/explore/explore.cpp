#include <bits/stdc++.h>

using namespace std;

long long t, n, m, x, y, d;
long long k, re;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> t;
    for (int i = 0; i < t; i++) {
        re = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        char maps[n+5][m+5];
        bool bmaps[n+5][m+5] = {0};
        for (int j = 1; j <= n; j++)
            cin >> maps[n];

        bmaps[x][y] = true;
        while (k--) {
            if (d == 0) {
                if (maps[x][y+1] != 'x' && y+1 > 0 && y+1 <= m) {
                    if (!bmaps[x][y+1]) {
                        bmaps[x][y+1] = true;
                        re++;
                    }
                    y++;
                }
                else d = (d+1)%4;
            }
            else if (d == 1) {
                if (maps[x+1][y] != 'x' && x+1 > 0 && x+1 <= n) {
                    if (!bmaps[x+1][y]) {
                        bmaps[x+1][y] = true;
                        re++;
                    }
                    x++;
                }
                else d = (d+1)%4;
            }
            else if (d == 2) {
                if (maps[x][y-1] != 'x' && y-1 > 0 && y-1 <= m) {
                    if (!bmaps[x][y-1]) {
                        bmaps[x][y-1] = true;
                        re++;
                    }
                    y--;
                }
                else d = (d+1)%4;
            }
            else if (d == 3) {
                if (maps[x-1][y] != 'x' && x-1 > 0 && x-1 <= n) {
                    if (!bmaps[x-1][y]) {
                        bmaps[x-1][y] = true;
                        re++;
                    }
                    x--;
                }
                else d = (d+1)%4;
            }
        }
        cout << re << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
