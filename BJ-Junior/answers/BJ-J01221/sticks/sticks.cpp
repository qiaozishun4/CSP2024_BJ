#include <iostream>
#include <cstdio>
using namespace std;
int n;
int ans[10] = {-1, -1,  1,  7,  4,  2,  6,  8};
int ans2[10] ={8, 10, 18, 22, 20, 28, 68, 88};
int main()
{
    //freopen("//home//csp-j//stick5089.in", "r", stdin);
    //freopen("//home//csp-j//stick5089.out", "w", stdout);
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n <= 7) cout << ans[n] << endl;
        else if(n % 7 == 3)
        {
            if(n == 10) cout << 22 << endl;
            else if(n == 17) cout << 200 << endl;
            else
            {
                cout << 200;
                int tm = (n - 17) / 7;
                for(int i = 1; i <= tm; i++) cout << 8;
                cout << endl;
            }
        }
        else
        {
            cout << ans2[n % 7];
            int tm = n / 7 - 1;
            for(int i = 1; i <= tm; i++) cout << 8;
            cout << endl;
        }
    }
    return 0;
}
