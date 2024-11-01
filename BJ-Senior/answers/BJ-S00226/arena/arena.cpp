#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int NR = 1e5 + 10;
int A[NR], c[NR], X[4], a[NR];
int n, m;
string d[100];

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >>n >>m;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= m; i++)
        cin >> c[i];
    for (int i = 1; i < 100; i++)
    {
        cin >> d[i];
        d[i] = d[i];
        if (d[i].length() == 1) break;
    }

    int T;
    cin >> T;
    while (T--)
    {
        for(int i = 0; i < 4; i++)
            cin >> X[i];
        for (int i = 1; i <= n; i++)
            a[i] = A[i] ^ X[i%4];

        ll ans = 0;
        for (int i = 1; i <= m; i++)
        {
            ll res = 0;
            if (c[i] == 1) res = 1;
            else {
                int K = 1;
                while ((1 << K) < c[i]) K++;
                int len = 1 << K;
                vector<vector<int>> ran;
                for (int j = 1; j <= len; j++)
                {
                    vector<int> tmp;
                    tmp.push_back(j);
                    ran.push_back(tmp);
                }

                for (int k = 1; k <= K; k++)
                {
                    vector<vector<int>> nxt;
                    for (int j = 0; j < ran.size(); j+=2)
                    {
                        vector<int> tmp;
                        bool ok = false;
                        if (d[k][j/2] == '0')
                        {
                            for (int small: ran[j])
                            {
                                if (small > c[i] || a[small] >= k)
                                    tmp.push_back(small);
                                if (small > c[i] || a[small] < k)
                                    ok = true;
                            }
                            if (ok)
                            {
                                for (int big: ran[j+1])
                                    tmp.push_back(big);
                            }
                        } else
                        {
                            for (int big: ran[j+1])
                            {
                                if (big > c[i] || a[big] >= k)
                                    tmp.push_back(big);
                                if (big > c[i] || a[big] < k)
                                    ok = true;
                            }
                            if (ok)
                            {
                                for (int small: ran[j])
                                    tmp.push_back(small);
                            }
                        }
                        nxt.push_back(tmp);
                    }
                    ran = nxt;
                }

                for (int small: ran[0])
                    res += small;
            }

            ans ^= res * i;
        }
        cout <<ans << endl;
    }

    return 0;
}

