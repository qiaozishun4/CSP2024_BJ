# include <iostream>
# include <algorithm>
# include <fstream>
using namespace std;
const int MAXN = 200005;
struct Block
{
    int s;
    int c;
} a[MAXN];
int t, ans;

void dfs (int dep, int len)
{
    if (dep > len)
    {
        int tmp = 0;
        for (int i = 1; i <= len; i++)
            for (int j = i - 1; j >= 1; j--)
                if (a[i].c == a[j].c)
                {
                    if (a[i].s == a[j].s)
                        tmp += a[i].s;
                    break;
                }
        ans = max (ans, tmp);
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        a[dep].c = i;
        dfs (dep + 1, len);
    }
    return;
}

int main ()
{
    freopen ("color.in", "r", stdin);
    freopen ("color.out", "w", stdout);
    cin >> t;
    for (int x = 1; x <= t; x++)
    {
        int n;
        ans = -1;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].s;
        a[1].c = 0;
        dfs (2, n);
        cout << ans << endl;
    }
    return 0;
}