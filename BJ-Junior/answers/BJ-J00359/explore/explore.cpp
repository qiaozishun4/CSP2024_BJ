#include <bits/stdc++.h>
using namespace std;
int T, n, m, k;
bool pos[1005][1005];
bool place[1005][1005];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >>T;
    for(int p = 1; p <= T; p++)
    {
        memset(pos, 0, sizeof(pos));
        memset(place, 0, sizeof(place));
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;

        int cnt = 1;
        place[x][y] = 1;
        for(int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            for(int j = 0; j < s.size(); j++)
            {
                if(s[j] == 'x') pos[i][j+1] = 1;
            }
        }
        if(pos[x][y+1] && pos[x+1][y] && pos[x-1][y] && pos[x][y-1])
        {
            cout << 1 << endl;
            continue;
        }
        if(k == 1)
        {
            if(d == 0)
            {
                if(!(y + 1 <= m && !pos[x][y + 1]))
                {
                    cout << 1 << endl;
                    continue;
                }
            }
            else if(d == 1)
            {
                if(!(x + 1 <= n && !pos[x + 1][y]))
                {
                    cout << 1 << endl;
                    continue;
                }
            }
            else if(d == 2)
            {
                if(!(y - 1 && !pos[x][y - 1]))
                {
                    cout << 1 << endl;
                    continue;
                }
            }
            else
            {
                if(!(x - 1 && !pos[x - 1][y]))
                {
                    cout << 1 << endl;
                    continue;
                }

            }
            cout << 2 << endl;continue;
        }
        for(int i = 1; i <= k; i++)
        {
            bool ff = 0;
            for(int l = 1; l <= 4; l++)
            {
                if(d == 0)
                {
                    if(y + 1 <= m && !pos[x][y + 1]) ff = 1;
                }
                else if(d == 1)
                {
                    if(x + 1 <= n && !pos[x + 1][y]) ff = 1;
                }
                else if(d == 2)
                {
                    if(y - 1 && !pos[x][y - 1]) ff = 1;
                }
                else
                {
                    if(x - 1 && !pos[x - 1][y]) ff = 1;
                }
                if(ff) break;
                else
                {
                    d = (d + 1) % 4;
                    i++;
                }
            }
            if(d == 0)
            {
                y++;
            }
            else if(d == 1)
            {
                x++;
            }
            else if(d == 2)
            {
                y--;
            }
            else if(d == 3)
            {
                x--;
            }
            if(!place[x][y])
            {
                cnt++;
                place[x][y] = 1;
            }
        }
        cout << cnt << endl;
    }
	return 0;
}
