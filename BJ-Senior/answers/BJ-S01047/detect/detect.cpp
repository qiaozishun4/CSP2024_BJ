#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct node
{
    int d;
    int v;
    int a;
};

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);


    int t, n, m, L, V, ans1, ans2;

    cin >> t;

    while(t--)
    {
        int d_max = -1, p[N];
        node car[N];

        cin >> n >> m >> L >> V;

        ans1 = ans2 = 0;

        for(int i = 1; i <= n; i++)
        {
            cin >> car[i].d >> car[i].v >> car[i].a;

            if(car[i].d > d_max)
                d_max = car[i].d;
        }

        int p_max = -1;

        for(int i = 1; i <= m; i++)
            cin >> p[i], p_max = max(p_max, p[i]);

        for(int i = 1; i <= n; i++)
        {
            if(car[i].d <= p_max)
            {
                if(car[i].v > V)
                    ans1++;
            }
        }

        int t = 1;

        while(p[t] < d_max)
             t++;

        if(ans1 == 0)
            ans2 = m;
        else
            ans2 = m - 1;

        cout << ans1 << " " << ans2 << "\n";
    }

    return 0;
}