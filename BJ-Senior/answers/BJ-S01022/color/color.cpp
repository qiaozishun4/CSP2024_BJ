#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int T, n, a[N], b[N], maxn, tt;
void dfs(int step, int le, int ri, int fen)
{
    if (step > n)
    {
        maxn = max(maxn, fen);
        return ;
    }
    if (a[step] == le)
    {
        dfs(step + 1, le, ri, fen + le);
    }
    else
    {
        dfs(step + 1, a[step], ri, fen);
    }
    if (a[step] == ri)
    {
        dfs(step + 1, le, ri, fen + ri);
    }
    else
    {
        dfs(step + 1, le, a[step], fen);
    }
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        if (n == 1)
        {
            cout << "0" << endl;
            continue;
        }
        if (n == 2)
        {
            if (a[1] == a[2]) cout << a[1] << endl;
            else cout << 0 << endl;
        }
        sort(b + 1, b + n + 1);
        bool f = 1;
        for (int i = 2; i <= n; i++)
        {
            if (b[i] == b[i - 1])
            {
                f = 0;
                break;//
            }
        }
        if (f)
        {
            cout << "0" << endl;
            continue;
        }
        maxn = 0;
        tt = 0;
        dfs(1, -1, -1, 0);
        cout << maxn << endl;
    }

    return 0;
}
