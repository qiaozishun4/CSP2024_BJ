#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
ll n, t, a[15], a1[15], b[10000000], c[15], num = 0, maxx = -100000000000000000000000000000000000, sum = 1;
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        for (int j = 1; j <= t; j++)
        {
            cin >> a[j];
        }
        for (int j = 1; j <= 2; j++)
        {
            a1[1] = j;
            for (int k = 1; k <= 2; k++)
            {
                a1[2] = k;
                for (int l = 1; l <= 2; l++)
                {
                    a1[3] = l;
                    for (int h = 1; h <= 2; h++)
                    {
                        a1[4] = h;
                        for (int g = 1; g <= 2; g++)
                        {
                            a1[5] = g;
                            for (int f = 1; f <= 2; f++)
                            {
                                a1[6] = f;
                                for (int d = 1; d <= 2; d++)
                                {
                                    a1[7] = d;
                                    for (int s = 1; s <= 2; s++)
                                    {
                                        a1[8] = s;
                                        for (int q = 1; q <= 2; q++)
                                        {
                                            a1[9] = q;
                                            for (int w = 1; w <= 2; w++)
                                            {
                                                a1[10] = w;
                                                for (int r = 1; r <= t; r++)
                                                {
                                                    for (int y = r + 1; y <= r; y++)
                                                    {
                                                        if (a1[y] == a1[r])
                                                        {
                                                            num = y;
                                                            break;
                                                        }
                                                    }
                                                    if (a1[num] == a1[r])
                                                    {
                                                        if (a[num] == a1[r])
                                                        {
                                                            c[r] = a1[r];
                                                        }
                                                        else
                                                        {
                                                            c[r] = 0;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        c[r] = 0;
                                                    }
                                                    b[sum] += c[r];
                                                }
                                                sum++;
                                                for (int p = 1; p < 15; p++)
                                                {
                                                    c[p] = 0;
                                                }
                                                maxx = max(maxx, b[sum - 1]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxx << endl;
        maxx = -10000000000000000000000000000000000000000000000000000000;
        num = 0;
        sum = 1;
        for (int m = 1; m < 10000000; m++)
        {
            b[i] = 0;
        }
        for (int v = 1; v < 15; v++)
        {
            a[i] = 0;
            a1[i] = 0;
            c[i] = 0;
        }
    }
    return 0;
}
