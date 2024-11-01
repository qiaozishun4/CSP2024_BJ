#include <bits/stdc++.h>
using namespace std;

char ma[1005][1005];

int main()
{
    freopen ("explore.in", "r", stdin);
    freopen ("explore.out", "w", stdout);
    int mt;
    cin >> mt;
    while (mt--)
    {
        memset(ma, 0, sizeof(ma));
        int mn, mm, mk, mx, my, md;
        scanf ("%d%d%d%d%d%d", &mn, &mm, &mk, &mx, &my, &md);
        for (int i = 1; i <= mn; i++)
        {
            for (int j = 1; j <= mm; j++)
            {
                cin >> ma[i][j];
            }
        }
        int mcnt = 0;
        for (int i = 1; i <= mk; i++)
        {
            if (md == 0) my++;
            else if (md == 1) mx++;
            else if (md == 2) my--;
            else if (md == 3) mx--;
            if (((mx < 1 || mx > mn) || (my < 1 || my > mm)) || ma[mx][my] == 'x')
            {
                if (i == 1) mcnt = 1;
                if (md == 0) my--;
                else if (md == 1) mx--;
                else if (md == 2) my++;
                else if (md == 3) mx++;
                md = (md + 1) % 4;
            }
            else
            {
                mcnt++;
            }
        }
        cout << mcnt << endl;
    }
    return 0;
}
