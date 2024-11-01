#include <iostream>
using namespace std;

int t, n, f[22]{0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888};

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n <= 21) cout << f[n] << endl;
        else
        {
            int k = (n - 1) / 7 - 2, u = n % 7;
            if(u == 0) u = 7;
            cout << f[u + 14];
            for(int i = 1; i <= k; i++) cout << "8";
            cout << endl;
        }
    }
    return 0;
}
