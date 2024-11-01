#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
ll n, a[100005], num = 0, minn = 10000000000000000000000000000000, mmin = 0, sum = 0;
bool b[100005], c[100005];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = 1;
        c[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
            {
                continue;
            }
            if ((a[i] <= a[j]) && b[i] == 1)
            {
                b[i] == 0;
                num++;
            }
        }
        if (num != i)
        {
            for (int j = 1; j <= n; i++)
            {
                if (a[j] < minn)
                {
                    minn = min(minn, a[j]);
                    mmin = j;
                }
            }
            c[mmin] = 0;
            b[mmin] = 0;
            num++;
            b[i] = 0;
        }
        minn = 10000000000000000000000000000000;
        mmin = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 1)
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
