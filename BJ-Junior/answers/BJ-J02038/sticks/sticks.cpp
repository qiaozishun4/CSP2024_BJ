#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; ++i) cout << 8;
            cout << endl;
            continue;
        }
        if (n % 7 == 1)
        {
            cout << 10;
            for (int i = 1; i <= n / 7 - 1; ++i) cout << 8;
            cout << endl;
            continue;
        }
        if (n % 7 == 2)
        {
            cout << 1;
            for (int i = 1; i <= n / 7; ++i) cout << 8;
            cout << endl;
            continue;
        }
        if (n % 7 == 3)
        {
            if (n >= 10)
            {
                cout << 22;
                for (int i = 1; i <= n / 7 - 1; ++i) cout << 8;
            }
            else cout << 7;
            cout << endl;
            continue;
        }
        if (n % 7 == 5)
        {
            cout << 2;
            for (int i = 1; i <= n / 7; ++i) cout << 8;
            cout << endl;
            continue;
        }
        if (n % 7 == 4)
        {
            if (n >= 11)
            {
                cout << 20;
                for (int i = 1; i <= n / 7 - 1; ++i) cout << 8;
            }
            else cout << 4;
            cout << endl;
            continue;
        }
        if (n % 7 == 6)
        {
            if (n == 6) cout << 6;
            else
            {
                cout << 80;
                for (int i = 1; i <= n / 7 - 1; ++i)
                {
                    cout << 8;
                }
            }
            cout << endl;
            continue;
        }
    }
    return 0;
}
