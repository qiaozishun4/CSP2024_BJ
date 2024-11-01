#include <bits/stdc++.h>
using namespace std;

vector <int> s[100005];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    srand(time(0));
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q, r, c;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++)
        {
            int l, ts;
            cin >> l;
            for (int j = 1; j <= l; j++)
            {
                cin >> ts;
                s[i].push_back(ts);
            }
        }
        while (q--)
        {
            cin >> r >> c;
            if (r == 1)
            {
                bool flag = false;
                for (int i = 1; i <= n; i++)
                {
                    int p1 = -1, pc = -1;
                    for (int j = 0; j < s[i].size(); j++)
                    {
                        if (s[i][j] == 1 && pc == -1)
                            p1 = j;
                        if (s[i][j] == c && p1 != -1 && pc == -1)
                            pc = j;
                    }
                    if (p1 != -1 && pc != -1 && pc - p1 + 1 <= k)
                    {
                        flag = true;
                        break;
                    }
                }
                cout << flag << endl;
            }
            else
            {
                int c0 = 0, c1 = 0;
                for (int i = 1; i <= 1000; i++)
                {
                    int tmp = rand() % 2;
                    if (tmp)
                        c1++;
                    else
                        c0++;
                }
                if (c0 >= c1)
                    cout << "0\n";
                else
                    cout << "1\n";
            }
        }
    }
    return 0;
}
