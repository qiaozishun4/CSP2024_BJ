#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, q, l;
int flag[200010];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> l;
            for (int j = 1; j <= l; j++)
            {
                int x; cin >> x;
                if (j != 1) flag[x] = 1;
            }
        }
        while (q--)
        {
            int r, c;
            cin >> r >> c;
            if (flag[c]) puts("1");
            else puts("0");
        }
    }
    return 0;
}