#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 5;
int n, mn = 1e9, a[NR];
bool debug = false, died[NR];

void dfs(int x, int live)
{
    if (x == n + 1)
    {
        if (debug)
        {
            for (int i = 1; i <= n; i++)
                cout << died[i] << " ";
            cout << "  live: " << live << endl;
        }
        mn = min(mn, live);
        return ;
    }

    if (died[x]) dfs(x + 1, live);
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!died[i] && x != i)
            {
                if (debug)
                {
                    if (x != 1) cout << " -> ";
                    cout << i;
                }

                if (a[x] <= a[i]) dfs(x + 1, live);
                else
                {
                    died[i] = true;
                    dfs(x + 1, live - 1);
                    died[i] = false;
                }
            }
        }
    }
}

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dfs(1, n);

    cout << mn << endl;
    return 0;
}