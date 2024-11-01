#include <bits/stdc++.h>
using namespace std;

int a[] = {0, -1, 1, 7, 4, 2, 6};

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
        if (n < 7)
        {
            cout << a[n];
        }
        else if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; i++)
            {
                cout << "8";
            }
        }
        else if (n % 7 == 1)
        {
            n -= 8;
            cout << "16";
            for (int i = 1; i <= n / 7; i++)
            {
                cout << "8";
            }
        }
        else if (n % 7 == 2)
        {
            cout << "1";
            n -= 2;
            for (int i = 1; i <= n / 7; i++)
            {
                cout << "8";
            }
        }
        else if (n % 7 == 3)
        {
            if (n == 10)
            {
                cout << "22";
            }
            else
            {
                cout << "200";
                n -= 17;
                for (int i = 1; i <= n / 7; i++)
                {
                    cout << "8";
                }
            }
        }
        else if (n % 7 == 4)
        {
            cout << "20";
            n -= 11;
            for (int i = 1; i <= n / 7; i++)
            {
                cout << "8";
            }
        }
        else if (n % 7 == 5)
        {
            cout << "2";
            n -= 5;
            for (int i = 1; i <= n / 7; i++)
            {
                cout << "8";
            }
        }
        else
        {
            cout << "6";
            n -= 6;
            for (int i = 1; i <= n / 7; i++)
            {
                cout << "8";
            }
        }
        cout << endl;
    }
    return 0;
}
