#include<bits/stdc++.h>
using namespace std;
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
//JESSE IS A CROOOOOOOOOOK!
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n < 2)
        {
            cout << -1;
            continue;
        }
        if (n ==2)
        {
            cout << 1 << endl;
            continue;
        }
        if (n == 3)
        {
            cout << 7 << endl;
            continue;
        }
        if (n == 4)
        {
            cout << 4 << endl;
            continue;
        }
        if (n == 5) {
            cout << 2 << endl;
            continue;
        }
        if (n == 6)
        {
            cout << 6 << endl;
            continue;
        }
        if (n == 7)
        {
            cout << 8 << endl;
            continue;
        }
        int naober = n / 7;
        if (n % 7 == 0)
        {
            for (int i = 1; i <= naober; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 1)
        {
            cout << 10;
            for (int i = 1; i <= naober; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 2)
        {
            cout << 1;
            for (int i = 1; i <= naober; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 3)
        {
            cout << 7;
            for (int i = 1; i <= naober; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 4)
        {
            cout << 20;
            for (int i = 1; i <= naober - 1; i++)
                cout << 8;
            cout << endl;
        }
        else if (n % 7 == 5)
        {
            cout << 2;
            for (int i = 1; i <= naober; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 6)
        {
            cout << 6;
            for (int i = 1; i <= naober; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}
