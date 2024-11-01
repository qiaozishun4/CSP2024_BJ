#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, l, v, s = 0, tt;
        cin >> n >> m >> l >> v;
        for (int i = 0; i < n; ++i)
        {
            cin >> tt >> l >> tt;
            if (l > v)
            {
                ++s;
            }
        }
        if (s)
        {
            cout << s << ' ' << m - 1 << '\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


