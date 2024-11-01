#include <cstdio>
#include <iostream>
using namespace std;

int t;

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1 || n == 0) cout << -1 << endl;
        else if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; i++)
                cout << 8;
            cout << endl;
        }
        else if ((n - 1) % 7 == 0)
        {
            cout << 1 << 0;
            for (int i = 1; i <= (n - 8) / 7; i++)
                cout << 8;
            cout << endl;
        }
        else if ((n - 2) % 7 == 0)
        {
            cout << 1;
            for (int i = 1; i <= (n - 2) / 7; i++)
                cout << 8;
            cout << endl;
        }
        else if ((n - 3) % 7 == 0)
        {
            if (n >= 17)
            {
                cout << 200;
                for (int i = 1; i <= (n - 17) / 7; i++)
                    cout << 8;
            }
            else if (n >= 10)
            {
                cout << 22;
                for (int i = 1; i <= (n - 10) / 7; i++)
                    cout << 8;
            }
            else cout << 7;
            cout << endl;
        }
        else if ((n - 4) % 7 == 0)
        {
            if (n >= 11)
            {
                cout << 20;
                for (int i = 1; i <= (n - 11) / 7; i++)
                    cout << 8;
            }
            else cout << 4;
            cout << endl;
        }
        else if ((n - 5) % 7 == 0)
        {
            cout << 2;
            for (int i = 1; i <= (n - 5) / 7; i++)
                cout << 8;
            cout << endl;
        }
        else if ((n - 6) % 7 == 0)
        {
            cout << 6;
            for (int i = 1; i <= (n - 6) / 7; i++)
                cout << 8;
            cout << endl;
        }
    }
    return 0;
}
