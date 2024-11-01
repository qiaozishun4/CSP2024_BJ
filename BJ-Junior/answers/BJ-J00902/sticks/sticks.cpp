#include <iostream>
using namespace std;

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << -1 << endl;
        }
        else if (n <= 6)
        {
            if (n == 2)
            {
                cout << 1 << endl;
            }
            else if (n == 3)
            {
                cout << 7 << endl;
            }
            else if (n == 4)
            {
                cout << 4 << endl;
            }
            else if (n == 5)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 6 << endl;
            }
        }
        else if (n % 7 == 0 || n % 7 == 6)
        {
            for (int i = 1; i <= n / 7; i++)
            {
                cout << 8;
            }
            if (n > 0)
            {
                cout << 0;
            }
            cout << endl;
        }
        else
        {
            cout << 2;
            n -= 5;
            while (n > 0)
            {
                if (n <= 5)
                {
                    if (n == 2)
                    {
                        cout << 1;
                    }
                    else if (n == 3)
                    {
                        cout << 7;
                    }
                    else if (n == 4)
                    {
                        cout << 4;
                    }
                    else if (n == 5)
                    {
                        cout << 2;
                    }
                    n = 0;
                }
                else if (n % 7 == 0)
                {
                    for (int i = 1; i <= n / 7; i++)
                    {
                        cout << 8;
                    }
                    n = 0;
                }
                else
                {
                    cout << 0;
                    n -= 6;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
