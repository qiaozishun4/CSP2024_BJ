#include <bits/stdc++.h>
using namespace std;
long long t;
struct stu
{
    char c;
    bool b=false;
};
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        long long n, m, k, x, y, d, num=1;
        stu s[1010][1010];
        string s1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> s1;
            for (int j = 1; j <= m; j++)
            {
                s[i][j].c = s1[j-1];
            }
        }
        s[x][y].b = true;
        for (int i = 1; i <= k; i++)
        {
            if (d == 0)
            {
                if (x >= 1 && x <= n && y+1 >= 1 && y+1 <= m && s[x][y+1].c == '.' && s[x][y+1].b == 0)
                {
                    s[x][y+1].b = true;
                    y++;
                    num++;
                }
                else if (x >= 1 && x <= n && y+1 >= 1 && y+1 <= m && s[x][y+1].c == '.' && s[x][y+1].b == 1)
                {
                    y++;
                }
                else
                {
                    d++;
                }
            }
            else if (d == 1)
            {
                if (x+1 >= 1 && x+1 <= n && y >= 1 && y <= m && s[x+1][y].c == '.' && s[x+1][y].b == 0)
                {
                    s[x+1][y].b = true;
                    x++;
                    num++;
                }
                else if (x+1 >= 1 && x+1 <= n && y >= 1 && y <= m && s[x+1][y].c == '.' && s[x+1][y].b == 1)
                {
                    x++;
                }
                else
                {
                    d++;
                }
            }
            else if (d == 2)
            {
                if (x >= 1 && x <= n && y-1 >= 1 && y-1 <= m && s[x][y-1].c == '.' && s[x][y-1].b == 0)
                {
                    s[x][y-1].b = true;
                    y--;
                    num++;
                }
                else if (x >= 1 && x <= n && y-1 >= 1 && y-1 <= m && s[x][y-1].c == '.' && s[x][y-1].b == 1)
                {
                    y--;
                }
                else
                {
                    d++;
                }
            }
            else if (d == 3)
            {
                if (x-1 >= 1 && x-1 <= n && y >= 1 && y <= m && s[x-1][y].c == '.' && s[x-1][y].b == 0)
                {
                    s[x-1][y].b = true;
                    x--;
                    num++;
                }
                else if (x-1 >= 1 && x-1 <= n && y >= 1 && y <= m && s[x-1][y].c == '.' && s[x-1][y].b == 1)
                {
                    x--;
                }
                else
                {
                    d = 0;
                }
            }
        }
        cout << num << endl;
    }
    return 0;
}
