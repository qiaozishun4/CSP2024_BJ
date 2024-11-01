#include <bits/stdc++.h>
using namespace std;

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
        if (n <= 1)
        {
            cout << "-1" << endl;
        }
        else if (n <= 7)
        {
            if (n == 2)
            {
                cout << "1" << endl;
            }
            else if (n == 3)
            {
                cout << "7" << endl;
            }
            else if (n == 4)
            {
                cout << "4" << endl;
            }
            else if (n == 5)
            {
                cout << "2" << endl;
            }
            else if (n == 6)
            {
                cout << "6" << endl;
            }
            else if (n == 7)
            {
                cout << "8" << endl;
            }

        }
        else
        {
            int a = n % 7;
            int b = n / 7;
            if (a == 0)
            {
                for (int i = 1; i <= b; i++)
                {
                    cout << "8";
                }
                cout << endl;
            }
            else
            {
                b -= 1;
                a += 7;
                if (a == 8)
                {
                    cout << "10";
                }
                else if (a == 9)
                {
                    cout << "18";
                }
                else if (a == 10)
                {
                    cout << "22";
                }
                else if (a == 11)
                {
                    cout << "20";
                }
                else if (a == 12)
                {
                    cout << "28";
                }
                else if (a == 13)
                {
                    cout << "68";
                }
                for (int i = 1; i <= b; i++)
                {
                    cout << "8";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
