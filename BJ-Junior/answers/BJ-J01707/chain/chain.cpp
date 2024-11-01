#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int i, j;
};

int t, n, k, q, l[100005], r, c;
bool flag;
vector<int> a[100005];
vector<node> p[200005];

inline void dfs(int x, int last, int lasti)
{
    if (x > r)
    {
        flag = true;
        return;
    }
    if (flag) return;
    for (auto e:p[last])
    {
        int ii = e.i, j = e.j;
        if (ii == lasti) continue;
        for (int i = j+1; i <= j + k - 1; ++i)
        {
            if (i == l[ii]) break;
            int num = a[ii][i];
            if (x == r && num != c) continue;
            dfs(x+1, a[ii][i], ii);
            if (flag) return;
        }
    }
}

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        int mx = 0;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; ++i)
        {
            int x;
            cin >> l[i];
            for (int j = 1; j <= l[i]; ++j)
            {
                cin >> x;
                a[i].push_back(x);
                p[x].push_back({i, j-1});
                mx = max(mx, x);
            }
        }
        while (q--)
        {
            flag = false;
            cin >> r >> c;
            dfs(1, 1, 0);
            if (flag) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        for (int i = 1; i <= n; ++i) a[i].clear();
        for (int i = 1; i <= mx; ++i) p[i].clear();
    }
    return 0;
}
