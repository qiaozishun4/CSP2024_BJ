#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        if (n < 2)
        {
            cout << -1 << '\n';
        }
        else if (n == 3)
        {
            cout << 7 << '\n';
        }
        else if (n == 4)
        {
            cout << 4 << '\n';
        }
        else if (n == 10)
        {
            cout << 22 << '\n';
        }
        else if (n % 7 == 0)
        {
            int len = n / 7;
            for (int j = 0; j < len; ++j)
            {
                cout << 8;
            }
            cout << '\n';
        }
        else if (n % 7 == 1)
        {
            cout << 10;
            int len = n / 7 - 1;
            for (int j = 0; j < len; ++j)
            {
                cout << 8;
            }
            cout << '\n';
        }
        else if (n % 7 == 2)
        {
            cout << 1;
            int len = n / 7;
            for (int j = 0; j < len; ++j)
            {
                cout << 8;
            }
            cout << '\n';
        }
        else if (n % 7 == 3)
        {
            cout << 200;
            int len = n / 7 - 2;
            for (int j = 0; j < len; ++j)
            {
                cout << 8;
            }
            cout << '\n';
        }
        else if (n % 7 == 4)
        {
            cout << 20;
            int len = n / 7 - 1;
            for (int j = 0; j < len; ++j)
            {
                cout << 8;
            }
            cout << '\n';
        }
        else if (n % 7 == 5)
        {
            cout << 2;
            int len = n / 7;
            for (int j = 0; j <len; ++j)
            {
                cout << 8;
            }
            cout << '\n';
        }
        else
        {
            cout << 6;
            int len = n / 7;
            for (int j = 0; j < len; ++j)
            {
                cout << 8;
            }
            cout << '\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
