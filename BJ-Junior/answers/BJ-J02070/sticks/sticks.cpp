#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in", "r" , stdin);
    freopen("sticks.out", "w", stdout);
    int T, s[15];
    long long ans = 1e9;
    s[0] = 6, s[1] = 2, s[2] = 5, s[3] = 5, s[4] = 4, s[5] = 5, s[6] = 6; s[7] = 3, s[8] = 7, s[9] = 6;
    cin >> T;
    for (int k = 1; k <= T; k++)
    {
        int n, ans = 0;
        cin >> n;
        if (n <= 1)
        {
            cout << -1;
        }
        if (n == 6)
        {
            cout << 6;
        }
        if (n == 5)
        {
            cout << 2;
        }
        else
        {
            for (int i = 0; i <= 9; i++)
            {
                if (n == s[i] && n != 6 && n != 5)
                {
                    cout << i;
                    ans = 0;
                }
            }
            if (ans != 0)
            {
                for (int a = 1; a <= 9; a++)
                {
                    for (int b = 0; b <= 9; b++)
                    {
                        if (s[a] + s[b] == n)
                        {
                            ans= min(ans, a * 10 + b);
                        }
                    }
                }
                for (int a = 1; a <= 9; a++)
                {
                    for (int b = 0; b <= 9; b++)
                    {
                        for (int c = 0; c <= 9; c++)
                        {
                            if (s[a] + s[b] + s[c] == n)
                            {
                                ans= min(ans, a * 100 + b * 10 + c);
                            }
                        }
                    }
                }
                for (int a = 1; a <= 9; a++)
                {
                    for (int b = 0; b <= 9; b++)
                    {
                        for (int c = 0; c <= 9; c++)
                        {
                            for (int d = 0; d <= 9; d++)
                            {
                                if (s[a] + s[b] + s[c] + s[d] == n)
                                {
                                    ans = min(ans, a * 1000 + b * 100 + c * 10 + d);
                                }
                            }
                        }
                    }
                }
                for (int a = 1; a <= 9; a++)
                {
                    for (int b = 0; b <= 9; b++)
                    {
                        for (int c = 0; c <= 9; c++)
                        {
                            for (int d = 0; d <= 9; d++)
                            {
                                for (int e = 0; e <= 9; e++)
                                {
                                    if (s[a] + s[b] + s[c] + s[d] + s[e] == n)
                                    {
                                        ans = min(ans, a * 10000 + b * 1000 + c * 100+ d * 10 + e);
                                    }
                                }
                            }
                        }
                    }
                }
                for (int a = 1; a <= 9; a++)
                {
                    for (int b = 0; b <= 9; b++)
                    {
                        for (int c = 0; c <= 9; c++)
                        {
                            for (int d = 0; d <= 9; d++)
                            {
                                for (int e = 0; e <= 9; e++)
                                {
                                    for (int f = 0; f <= 9; f++)
                                    {
                                        if (s[a] + s[b] + s[c] + s[d] + s[e] + s[f]== n)
                                        {
                                            ans = min(ans, a * 100000 + b * 10000 + c * 1000+ d * 100 + e * 10 + f);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                for (int a = 1; a <= 9; a++)
                {
                    for (int b = 0; b <= 9; b++)
                    {
                        for (int c = 0; c <= 9; c++)
                        {
                            for (int d = 0; d <= 9; d++)
                            {
                                for (int e = 0; e <= 9; e++)
                                {
                                    for (int f = 0; f <= 9; f++)
                                    {
                                        for (int g = 0; g <= 9; g++)
                                        {
                                            if (s[a] + s[b] + s[c] + s[d] + s[e] + s[f] + s[g] == n)
                                            {
                                                ans = min(ans, a * 1000000 + b * 100000 + c * 10000 + d * 1000 + e * 100 + f * 10 + g);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                for (int a = 1; a <= 9; a++)
                {
                    for (int b = 0; b <= 9; b++)
                    {
                        for (int c = 0; c <= 9; c++)
                        {
                            for (int d = 0; d <= 9; d++)
                            {
                                for (int e = 0; e <= 9; e++)
                                {
                                    for (int f = 0; f <= 9; f++)
                                    {
                                        for (int g = 0; g <= 9; g++)
                                        {
                                            for (int h = 0; h <= 9; h++)
                                            {
                                                if (s[a] + s[b] + s[c] + s[d] + s[e] + s[f] + s[g] + s[h] == n)
                                                {
                                                    ans = min(ans, a * 10000000 + b * 1000000 + c * 100000 + d * 10000 + e * 1000 + f * 100 + g * 10 + h);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (ans != 1e9)
                {
                    cout << ans;
                }
                else
                {
                    cout << -1;
                }
            }
        }
    }
    return 0;
}
