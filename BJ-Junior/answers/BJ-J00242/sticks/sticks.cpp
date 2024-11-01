#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
ll t, x, sum[1000005], num = 1, nnuumm = 1;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> x;
        if (x == 1)
        {
            sum = -1;
            cout << sum;
            sum = 0;
            continue;
        }
        if (x == 7)
        {
            sum = 8;
            cout << sum;
            sum = 0;
            continue;
        }
        while (x > 0)
        {
            if (num == 1)
            {
                if (x - 7 > 1)
                {
                    sum[nnuumm] = 8;
                    nnuumm++;
                }
                else if (x == 8)
                {
                    sum[nnuumm] = 10;
                    nnuumm++;
                }
                else if (x == 6)
                {
                    sum[nnuumm] = 6;
                    nnuumm++;
                }
                else if (x == 5)
                {
                    sum[nnuumm] = 2;
                    nnuumm++;
                }
                else if (x == 4)
                {
                    sum[nnuumm] = 4;
                    nnuumm++;
                }
                else if (x == 3)
                {
                    sum[nnuumm] = 7;
                    nnuumm++;
                }
                else if (x == 2)
                {
                    sum[nnuumm] = 1;
                    nnuumm++;
                }
                num++;
                continue;
            }
            else
            {
                if (x - 6 > 1)
                {
                    sum[nnuumm] = 0;
                    nnuumm++;
                }
                else if (x == 7)
                {
                    sum[nnuumm] = 8;
                    nnuumm++;
                }
                else if (x == 6)
                {
                    sum[nnuumm] = 6;
                    nnuumm++;
                }
                else if (x == 5)
                {
                    sum[nnuumm] = 2;
                    nnuumm++;
                }
                else if (x == 4)
                {
                    sum[nnuumm] = 4;
                    nnuumm++;
                }
                else if (x == 3)
                {
                    sum[nnuumm] = 7;
                    nnuumm++;
                }
                else if (x == 2)
                {
                    sum[nnuumm] = 1;
                    nnuumm++;
                }
            }
        }
        for (int i = nnuumm - 1; i >= 1; i++)
        {
            cout << sum[i];
        }
        cout << endl;
        num = 1;
        sum = 0;
        ssum = 0;
    }
    return 0;
}