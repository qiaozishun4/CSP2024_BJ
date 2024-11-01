#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int NR = 1e5 + 5;

int T, n;
int mxn = 0;
int b[20] = {-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    cin >> T;
    for (int i = 1;i <= T;i ++)
    {
        cin >> n;
        if (n <= 14)
        {
            cout << b[n] << '\n';
        }
        else if (n % 7 == 0)
        {
            for (int j = 0;j < n;j += 7)
                cout << '8';
            cout << '\n';
        }
        else if (n % 7 == 1)
        {
            cout << "10";
            for (int j = 14;j < n;j += 7)
                cout << '8';
            cout << '\n';
        }
        else if (n % 7 == 2)
        {
            cout << "18";
            for (int j = 14;j < n;j += 7)
                cout << '8';
            cout << '\n';
        }
        else if (n % 7 == 3)
        {
            cout << "200";
            for (int j = 21;j < n;j += 7)
                cout << '8';
            cout << '\n';
        }
        else if (n % 7 == 4)
        {
            cout << "208";
            for (int j = 21;j < n;j += 7)
                cout << '8';
            cout << '\n';
        }
        else if (n % 7 == 5)
        {
            cout << "288";
            for (int j = 21;j < n;j += 7)
                cout << '8';
            cout << '\n';
        }
        else if (n % 7 == 6)
        {
            cout << "688";
            for (int j = 21;j < n;j += 7)
                cout << '8';
            cout << '\n';
        }
    }
    return 0;
}
