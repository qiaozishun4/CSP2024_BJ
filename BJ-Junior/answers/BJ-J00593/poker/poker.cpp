#include <iostream>
#include <cstdio>
using namespace std;

char c[10] = {'D', 'C', 'H', 'S'};
char p[20] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
bool vis[10][20];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, ans = 0;
    char clr, pnt;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> clr >> pnt;
        int tc, tp;
        for (int i = 0; i < 4; i++)
        {
            if (c[i] == clr)
            {
                tc = i;
                break;
            }
        }
        for (int i = 0; i < 13; i++)
        {
            if (p[i] == pnt)
            {
                tp = i;
                break;
            }
        }
        vis[tc][tp] = true;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (!vis[i][j])
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
