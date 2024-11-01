#include <cstdio>
#include <iostream>
using namespace std;
const int num[10] = {6,2,5,5,4,5,6,3,7,6};
int T,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << -1 << endl;
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
        if (n == 10)
        {
            cout << 22 << endl;
            continue;
        }
        int k = n / 7,m = n % 7;
        if (m == 0)
        {
            while (k--)
            {
                cout << 8;
            }
            cout << endl;
        }
        if (m == 1)
        {
            cout << 10;
            k--;
            while (k--)
            {
                cout << 8;
            }
            cout << endl;
        }
        if (m == 2)
        {
            cout << 1;
            while (k--)
            {
                cout << 8;
            }
            cout << endl;
        }
        if (m == 3)
        {
            cout << 200;
            k -= 2;
            while (k--)
            {
                cout << 8;
            }
            cout << endl;
        }
        if (m == 4)
        {
            cout << 20;
            k--;
            while (k--)
            {
                cout << 8;
            }
            cout << endl;
        }
        if (m == 5)
        {
            cout << 2;
            while (k--)
            {
                cout << 8;
            }
            cout << endl;
        }
        if (m == 6)
        {
            cout << 6;
            while (k--)
            {
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}