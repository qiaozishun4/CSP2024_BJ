#include <bits/stdc++.h>
using namespace std;

int n;

struct b
{
    int r, tot = 0;
    bool flag = false;
}a[100001];

bool rfj (b x, b y)
{
    return x.r < y.r;
}

bool alldone ()
{
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].r != 0 && a[i].flag == false) flag = false;
    }
    return flag;
}

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].r;
    }
    sort(a + 1, a + n + 1, rfj);
    while(!alldone())
    {
        for (int i = 1;i <= n; i++)
        {
            if(a[i].r != 0)
            {
                int bestj, bestf = 1000000000;
                for (int j = i + 1; j <= n; j++)
                {
                    if(a[j].r > a[i].r && a[j].tot < bestf)
                    {
                        bestf = a[j].tot;
                        bestj = j;
                    }
                    a[i].r = 0;
                    a[j].flag = true;
                    a[j].tot++;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].r != 0) cnt++;
    }
    cout << cnt + 1 << endl;

    return 0;
}
