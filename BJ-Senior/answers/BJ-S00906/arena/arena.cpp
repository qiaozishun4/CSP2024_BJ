#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int a[100005], t[100005], c[100005], x[5], tree[100005];
string s[100005];
int main()
{
    //freopen("arena.in", "r", stdin);
    //freopen("arena.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t[i] = a[i];
    }
    for (int i = 1; i <= m; i++) cin >> c[i];
    int k = 0;
    for (int i = 0; i <= 31; i++)
    {
        if (int(pow(2, i)) >= n)
        {
            k = i;
            break;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> s[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        memcpy(t, a, sizeof(t));
        for (int i = 0; i < 4; i++)
        {
            cin >> x[i];
        }
        for (int i = 1; i <= int(pow(2, k)); i++)
        {
            a[i] = a[i] ^ x[i % 4];
            tree[i] = a[i];
        }
        long long sum = 0;
        int y = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; ; j++)
            {
                if (int(pow(2, j)) >= c[i])
                {
                    y = j;
                    break;
                }
            }
            for (int i = 1; i <= y; i++)
            {
                for (int j = 0; j < s[i].size(); j++)
                {
                    if (s[i][j] == '0')
                    {
                        if (tree[2 * (j + 1) - 1] < i) tree[j + 1] = tree[2 * (j + 1)];
                        else tree[j + 1] = tree[2 * (j + 1) - 1];
                    }
                    else
                    {
                        if (tree[2 * (j + 1) - 1] < i) tree[j + 1] = tree[2 * (j + 1)];
                        else tree[j + 1] = tree[2 * (j + 1) - 1];
                    }
                }
            }
            cout << tree[1] <<endl;
        }
    }
    return 0;
}
