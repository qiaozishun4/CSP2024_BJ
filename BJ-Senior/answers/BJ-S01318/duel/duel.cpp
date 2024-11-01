#include <iostream>
#include <cstdio>

using namespace std;

const int MX = 1e5;

int n, r;
int cnt[MX];

int main(void)
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r;
        cnt[--r]++;
    }

    for (int i = 0; i < MX - 1; i++)
    {
        if (cnt[i] <= cnt[i + 1])
        {
            n -= cnt[i];
        }
        else
        {
            n -= cnt[i + 1];
            // cnt[i + 1] += cnt[i] - cnt[i + 1];
            cnt[i + 1] = cnt[i];
        }
    }
    cout << n << endl;

    return 0;
}