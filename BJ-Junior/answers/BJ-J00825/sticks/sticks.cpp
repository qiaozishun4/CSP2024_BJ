#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    while (n--)
    {
        cin >> a;
        if (a == 1)
            cout << -1 << '\n';
        if (a == 2)
            cout << 1 << '\n';
        if (a == 3)
            cout << 7 << '\n';
        if (a == 4)
            cout << 4 << '\n';
        if (a == 5)
            cout << 2 << '\n';
        if (a == 6)
            cout << 6 << '\n';
        if (a == 7)
            cout << 8 << '\n';
        if (a == 8)
            cout << 10 << '\n';
        if (a == 9)
            cout << 18 << '\n';
        if (a == 10)
            cout << 22 << '\n';
        if (a == 11)
            cout << 26 << '\n';
        if (a == 12)
            cout << 28 << '\n';
        if (a == 13)
            cout << 68 << '\n';
        if (a == 14)
            cout << 88 << '\n';
        if (a == 15)
            cout << 108 << '\n';
        if (a == 16)
            cout << 188 << '\n';
        if (a == 17)
            cout << 228 << '\n';
        if (a == 18)
            cout << 208 << '\n';
        if (a == 19)
            cout << 288 << '\n';
        if (a == 20)
            cout << 688 << '\n';
        if (a == 21)
            cout << 888 << '\n';
        if (a == 22)
            cout << 1688 << '\n';
        if (a == 23)
            cout << 1888 << '\n';
        if (a == 24)
            cout << 2288 << '\n';
        if (a == 25)
            cout << 2688 << '\n';
        if (a == 26)
            cout << 2888 << '\n';
        if (a == 27)
            cout << 6888 << '\n';
        if (a == 28)
            cout << 8888 << '\n';
        if (a % 7 == 0 && a >= 35)
        {
            int x = a / 7;
            for (int j = 0; j < x; j++)
                cout << 8;
            cout << '\n';
        }
    }
    return 0;
}
