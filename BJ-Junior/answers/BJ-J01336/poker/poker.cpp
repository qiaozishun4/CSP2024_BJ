#include <iostream>
using namespace std;

int d[14], c[14], h[14], s[14];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        string color;
        cin >> color;
        if (color[0] == 'D')
        {
            if (color[1] == 'A')
            {
                d[1] = 1;
                continue;
            }
            else if (color[1] == 'T')
            {
                d[10] = 1;
                continue;
            }
            else if (color[1] == 'J')
            {
                d[11] = 1;
                continue;
            }
            else if (color[1] == 'Q')
            {
                d[12] = 1;
                continue;
            }
            else if (color[1] == 'K')
            {
                d[13] = 1;
                continue;
            }
            d[color[1] - '0'] = 1;
        }
        else if (color[0] == 'C')
        {
            if (color[1] == 'A')
            {
                c[1] = 1;
                continue;
            }
            else if (color[1] == 'T')
            {
                c[10] = 1;
                continue;
            }
            else if (color[1] == 'J')
            {
                c[11] = 1;
                continue;
            }
            else if (color[1] == 'Q')
            {
                c[12] = 1;
                continue;
            }
            else if (color[1] == 'K')
            {
                c[13] = 1;
                continue;
            }
            c[color[1] - '0'] = 1;
        }
        else if (color[0] == 'H')
        {
            if (color[1] == 'A')
            {
                h[1] = 1;
                continue;
            }
            else if (color[1] == 'T')
            {
                h[10] = 1;
                continue;
            }
            else if (color[1] == 'J')
            {
                h[11] = 1;
                continue;
            }
            else if (color[1] == 'Q')
            {
                h[12] = 1;
                continue;
            }
            else if (color[1] == 'K')
            {
                h[13] = 1;
                continue;
            }
            h[color[1] - '0'] = 1;
        }
        else
        {
            if (color[1] == 'A')
            {
                s[1] = 1;
                continue;
            }
            else if (color[1] == 'T')
            {
                s[10] = 1;
                continue;
            }
            else if (color[1] == 'J')
            {
                s[11] = 1;
                continue;
            }
            else if (color[1] == 'Q')
            {
                s[12] = 1;
                continue;
            }
            else if (color[1] == 'K')
            {
                s[13] = 1;
                continue;
            }
            s[color[1] - '0'] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 13; ++ i)
    {
        ans += 1 - d[i];
    }
    for (int i = 1; i <= 13; ++ i)
    {
        ans += 1 - c[i];
    }
    for (int i = 1; i <= 13; ++ i)
    {
        ans += 1 - h[i];
    }
    for (int i = 1; i <= 13; ++ i)
    {
        ans += 1 - s[i];
    }
    cout << ans << endl;
    return 0;
}