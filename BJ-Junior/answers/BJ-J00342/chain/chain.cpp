#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 2e5 + 5;

int n, k, q;
string a[N];
bool can = false;

void dfs(int r, char c, int lid, char lnum, bool first)
{
    if (r == 0)
    {
        if (lnum == c) can = true;
        return;
    }
    if (first)
    {
        first = false;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < a[i].size(); j++)
                if (a[i][j] == '1')
                {
                    for (int lek = 2; lek <= k; lek++)
                    {
                        string t = "";
                        if (j + lek >= a[i].size()) t = a[i].substr(j);
                        else t = a[i].substr(j, lek);
                        dfs(r - 1, c, i, t[t.size() - 1], first);
                    }
                }
    }
    else
    {
        for (int i = 1; i <= n; i++)
            if (i != lid)
            {
                for (int j = 0; j < a[i].size(); j++)
                    if (a[i][j] == lnum)
                    {
                        for (int lek = 2; lek <= k; lek++)
                        {
                            string t = "";
                            if (j + lek >= a[i].size()) t = a[i].substr(j);
                            else t = a[i].substr(j, lek);
                            dfs(r - 1, c, i, t[t.size() - 1], first);
                        }
                    }
            }
    }
}

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    for (int tst = 1; tst <= T; tst++)
    {
        can = false;
        cin >> n >> k >> q;
        bool f = true;
        for (int i = 1; i <= n; i++)
        {
            a[i] = "";
            int l;
            cin >> l;
            for (int j = 1; j <= l; j++)
            {
                int x;
                cin >> x;
                if (x == 1) f = false;
                a[i] += to_string(x);
            }
        }
        for (int tsq = 1; tsq <= q; tsq++)
        {
            int r, c;
            cin >> r >> c;
            if (f) cout << "0\n";
            char ch = (c + '0');
            dfs(r, ch, 0, '0', 1);
            if (can) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}
