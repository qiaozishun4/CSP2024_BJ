#include <iostream>

using namespace std;

int main()
{
    int T, n, m, p;
    freopen("stick.in", "r", stdin);
    freopen("stick.out", "w", stdout);
    cin >> T;
    for (int z = 0; z < T; z++)
    {
        cin >> n;
        m = n / 7;
        if (n % 7 == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << '8';
            }
            cout << endl;
            continue;
        }
        else if (n % 7 == 1)
        {
            if (n == 1)
            {
                cout << -1 << endl;
                continue;
            }
            cout << '1' << '0';
            for (int i = 0; i < m - 1; i++)
            {
                cout << '8';
            }
            cout << endl;
            continue;
        }
        else if (n % 7 == 2)
        {
            cout << 1;
            if (n == 2)
            {
                cout << endl;
                continue;
            }
            for (int i = 0; i < m; i++)
            {
                cout << '8';
            }
            cout << endl;
            continue;
        }
        else if (n % 7 == 3)
        {
            if (n == 3)
            {
                cout << '7' << endl;
                continue;
            }
            else if (n == 10)
            {
                cout << "22" << endl;
                continue;
            }
            else if (n == 17)
            {
                cout << "200" << endl;
                continue;
            }
            else
            {
                cout << "200";
                for (int i = 0; i < m - 2; i++)
                {
                    cout << '8';
                }
                cout << endl;
                continue;
            }
        }
        else if (n % 7 == 4)
        {
            if (n == 4)
            {
                cout << 4 << endl;
                continue;
            }
            else if (n == 11)
            {
                cout << 20 << endl;
                continue;
            }
            else
            {
                cout << 20;
                for (int i = 0; i < m - 1; i++)
                {
                    cout << 8;
                }
                cout << endl;
                continue;
            }
        }
        else if (n % 7 == 5)
        {
            if (n == 5)
            {
                cout << 2 << endl;
                continue;
            }
            else
            {
                cout << 2;
                for (int i = 0; i < m; i++)
                {
                    cout << 8;
                }
                cout << endl;
                continue;
            }
        }
        else
        {
            cout << 6;
            for (int i = 0; i < m; i++)
            {
                cout << 8;
            }
            cout << endl;
            continue;
        }
    }
    return 0;
}
