# include <bits/stdc++.h>
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
        if (n >= 1 && n <= 7)
        {
            if (n == 1)
                cout << -1 << endl;
            if (n == 2)
                cout << 1 << endl;
            if (n == 3)
                cout << 7 << endl;
            if (n == 4)
                cout << 4 << endl;
            if (n == 5)
                cout << 2 << endl;
            if (n == 6)
                cout << 6 << endl;
            if (n == 7)
                cout << 8 << endl;
            continue;
        }
        if (n == 10)
        {
            cout << 22 << endl;
            continue;
        }
        int a, b;
        a = n / 7;
        b = n % 7;
        if (b == 0)
        {
            for (int j = 1; j <= a; j++)
                cout << 8;
            cout << endl;
        }
        if (b == 1)
        {
            cout << 10;
            for (int j = 1; j <= a-1; j++)
                cout << 8;
            cout << endl;
        }
        if (b == 2)
        {
            cout << 1;
            for (int j = 1; j <= a; j++)
                cout << 8;
            cout << endl;
        }
        if (b == 3)
        {
            cout << 200;
            for (int j = 1; j <= a-2; j++)
                cout << 8;
            cout << endl;
        }
        if (b == 4)
        {
            cout << 20;
            for (int j = 1; j <= a-1; j++)
                cout << 8;
            cout << endl;
        }
        if (b == 5)
        {
            cout << 2;
            for (int j = 1; j <= a; j++)
                cout << 8;
            cout << endl;
        }
        if (b == 6)
        {
            cout << 6;
            for (int j = 1; j <= a; j++)
                cout << 8;
            cout << endl;
        }
    }
    return 0;
}
