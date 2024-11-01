#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
    freopen("stick.in", "r", stdin);
    freopen("stick.in", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        if (n == 1)
        {
            cout << -1 << endl;
        }
        if (n == 2)
        {
            cout << 1 << endl;
        }
        if (n == 3)
        {
            cout << 7 << endl;
        }
        if (n == 4)
        {
            cout << 4 << endl;
        }
        if (n == 5)
        {
            cout << 2 << endl;
        }
        if (n == 6)
        {
            cout << 6 << endl;
        }
        if (n == 7)
        {
            cout << 8 << endl;
        }
        if (n == 8)
        {
            cout << 10 << endl;
        }
        if (n == 9)
        {
            cout << 18 << endl;
        }
        if (n == 10)
        {
            cout << 22 << endl;
        }
        if (n == 11)
        {
            cout << 26 << endl;
        }
        if (n == 12)
        {
            cout << 28 << endl;
        }
        if (n == 13)
        {
            cout << 68 << endl;
        }
        if (n == 14)
        {
            cout << 88 << endl;
        }
        if (n == 15)
        {
            cout << 108 << endl;
        }
        if (n == 16)
        {
            cout << 188 << endl;
        }
        if (n == 17)
        {
            cout << 206 << endl;
        }
        if (n == 18)
        {
            cout << 208 << endl;
        }
        if (n == 19)
        {
            cout << 288 << endl;
        }
        if (n == 20)
        {
            cout << 688 << endl;
        }
        if (n == 21)
        {
            cout << 888 << endl;
        }
        if (n == 22)
        {
            cout << 1088 << endl;
        }
        if (n == 23)
        {
            cout << 1888 << endl;
        }
        if (n == 24)
        {
            cout << 2008 << endl;
        }
        if (n == 25)
        {
            cout << 2088 << endl;
        }
        if (n == 26)
        {
            cout << 2888 << endl;
        }
        if (n == 27)
        {
            cout << 6888 << endl;
        }
        if (n == 28)
        {
            cout << 8888 << endl;
        }
        if (n == 29)
        {
            cout << 10888 << endl;
        }
        if (n == 30)
        {
            cout << 18888 << endl;
        }
        if (n == 31)
        {
            cout << 20088 << endl;
        }
        if (n == 32)
        {
            cout << 20888 << endl;
        }
        if (n == 33)
        {
            cout << 28888 << endl;
        }
        if (n == 34)
        {
            cout << 68888 << endl;
        }
        if (n == 35)
        {
            cout << 88888 << endl;
        }
        if (n == 36)
        {
            cout << 108888 << endl;
        }
        if (n == 37)
        {
            cout << 188888 << endl;
        }
        if (n == 38)
        {
            cout << 200888 << endl;
        }
        if (n == 39)
        {
            cout << 208888 << endl;
        }
        if (n == 40)
        {
            cout << 288888 << endl;
        }
        if (n == 41)
        {
            cout << 688888 << endl;
        }
        if (n == 42)
        {
            cout << 888888 << endl;
        }
        if (n == 43)
        {
            cout << 1088888 << endl;
        }
        if (n == 44)
        {
            cout << 1888888 << endl;
        }
        if (n == 45)
        {
            cout << 2008888 << endl;
        }
        if (n == 46)
        {
            cout << 2088888 << endl;
        }
        if (n == 47)
        {
            cout << 2888888 << endl;
        }
        if (n == 48)
        {
            cout << 6888888 << endl;
        }
        if (n == 49)
        {
            cout << 8888888 << endl;
        }
        if (n == 50)
        {
            cout << 10888888 << endl;
        }
        if (n >= 51 && n % 7 == 0)
        {
            string ans = "";
            for (int j = 1; j <= n / 7; j++)
            {
                ans += '8';
            }
            cout << ans << endl;
        }
        if (n >= 51 && n % 7 == 1)
        {
            string ans = "10";
            for (int j = 1; j < (n - 1) / 7; j++)
            {
                ans += '8';
            }
            cout << ans << endl;
        }
        if (n >= 51 && n % 7 == 2)
        {
            string ans = "18";
            for (int j = 1; j < (n - 1) / 7; j++)
            {
                ans += '8';
            }
            cout << ans << endl;
        }
        if (n >= 51 && n % 7 == 3)
        {
            string ans = "200";
            for (int j = 2; j < (n - 1) / 7; j++)
            {
                ans += '8';
            }
            cout << ans << endl;
        }
        if (n >= 51 && n % 7 == 4)
        {
            string ans = "20";
            for (int j = 1; j < (n - 1) / 7; j++)
            {
                ans += '8';
            }
            cout << ans << endl;
        }
        if (n >= 51 && n % 7 == 5)
        {
            string ans = "2";
            for (int j = 1; j <= (n - 1) / 7; j++)
            {
                ans += '8';
            }
            cout << ans << endl;
        }
        if (n >= 51 && n % 7 == 6)
        {
            string ans = "6";
            for (int j = 1; j <= (n - 1) / 7; j++)
            {
                ans += '8';
            }
            cout << ans << endl;
        }
    }
    return 0;
}
