#include <iostream>
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

        if (n % 7 == 0) // 888...
        {
            for (int i = 7; i <= n; i += 7) cout << 8;
            cout << endl;
        }
        else if (n % 7 == 1) // 10888...
        {
            if (n == 1)
            {
                cout << "-1" << endl;
                continue;
            }
            cout << "10"; n -= 8;
            for (int i = 7; i <= n; i += 7) cout << 8;
            cout << endl;
        }
        else if (n % 7 == 2) // 1888...
        {
            cout << "1"; n -= 2;
            for (int i = 7; i <= n; i += 7) cout << 8;
            cout << endl;
        }
        else if (n % 7 == 3) // 2288...
        {
            if (n == 3)
            {
                cout << "7" << endl;
                continue;
            }
            cout << "22"; n -= 10;
            for (int i = 7; i <= n; i += 7) cout << 8;
            cout << endl;
        }
        else if (n % 7 == 4) // 2088...
        {
            if (n == 4)
            {
                cout << "4" << endl;
                continue;
            }
            cout << "20"; n -= 11;
            for (int i = 7; i <= n; i += 7) cout << 8;
            cout << endl;
        }
        else if (n % 7 == 5) // 2888...
        {
            cout << "2"; n -= 5;
            for (int i = 7; i <= n; i += 7) cout << 8;
            cout << endl;
        }
        else if (n % 7 == 6) // 6888...
        {
            cout << "6"; n -= 6;
            for (int i = 7; i <= n; i += 7) cout << 8;
            cout << endl;
        }
    }

    return 0;
}