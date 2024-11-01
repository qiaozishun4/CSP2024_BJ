#include <cstdio>
#include <iostream>
using namespace std;
int m[8] = {0, 0, 1, 7, 4, 2, 6, 8};
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
        if (n <= 7)
        {
            cout << m[n] << endl;
        }
        else if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; i++)
            {
                cout << "8";
            }
            cout << endl;
        }
        else if ((n - 1) % 7 == 0)
        {
            cout << "10";
            for (int i = 1; i <= (n - 8) / 7; i++)
            {
                cout << "8";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
