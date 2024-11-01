#include <iostream>
#include <cstdio>
using namespace std;

int f[] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 80, 88, 108, 202, 200, 208, 288, 808, 888, 1088, 1888, 2008, 2088, 2888, 8088, 8888, 10888};

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n % 7 == 0)
        {
            for(int i = 1; i <= n / 7; i++)
                cout << 8;
            cout << endl;
        }
        else if(n % 7 == 1)
        {
            cout << 20;
            for(int i = 1; i <= n / 7 - 1; i++)
                cout << 8;
            cout << endl;
        }
        else if(n >= 30) cout << -1 << endl;
        else cout << f[n] << endl;
    }
    return 0;
}
