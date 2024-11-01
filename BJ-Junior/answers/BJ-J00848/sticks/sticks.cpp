#include <iostream>
using namespace std;

int f[60], num[10] = {6,2,5,5,4,5,6,3,7,6};

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= 20000000; i++)
    {
        int cnt = 0, x = i;
        while (x != 0)
        {
            cnt += num[x % 10];
            x /= 10;
        }
        if (f[cnt] == 0)  f[cnt] = i;
        if (cnt == 50)  break;
    }
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)  cout << -1;
        else if (n <= 50)  cout << f[n];
        else if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; i++)  cout << 8;
        }
        else if (n % 7 == 1)
        {
            cout << 10;
            for (int i = 1; i <= n / 7 - 1; i++)  cout << 8;
        }
        else if (n % 7 == 2)
        {
            cout << 1;
            for (int i = 1; i <= n / 7; i++)  cout << 8;
        }
        else if (n % 7 == 3)
        {
            cout << 200;
            for (int i = 1; i <= n / 7 - 2; i++)  cout << 8;
        }
        else if (n % 7 == 4)
        {
            cout << 20;
            for (int i = 1; i <= n / 7 - 1; i++)  cout << 8;
        }
        else if (n % 7 == 5)
        {
            cout << 2;
            for (int i = 1; i <= n / 7; i++)  cout << 8;
        }
        else if (n % 7 == 6)
        {
            cout << 6;
            for (int i = 1; i <= n / 7; i++)  cout << 8;
        }
        cout << endl;
    }
    return 0;
}