#include<bits/stdc++.h>
using namespace std;
int T, n, m, k, x, y, d, cnt = 1;
const int ch[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char b[1005][1005];
bool c[1005][1005];
int main()
{
    cin >> T;
    while (T--)
    {
        freopen("explore.in", "r", stdin);
        freopen("explore.out", "w", stdout);
        cin >> n >> m >> k >> x >> y >> d;
        x--; y--;
        cnt = 1;
        memset(c, 0, sizeof(c));
        c[y][x] = true;
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < k; i++)
        {
            if (b[y + ch[d][1]][x + ch[d][0]] == '.' && x + ch[d][0] > -1 && x + ch[d][0] < m && y + ch[d][1] > -1 && y + ch[d][1] < n)
            {
                cnt += !c[y + ch[d][1]][x + ch[d][0]];
                c[y + ch[d][1]][x + ch[d][0]] = true;
                x = x + ch[d][0];
                y = y + ch[d][1];
            }
            else d = (d + 1) % 4;
        }
        cout << cnt << endl;
    }
    return 0;
}
