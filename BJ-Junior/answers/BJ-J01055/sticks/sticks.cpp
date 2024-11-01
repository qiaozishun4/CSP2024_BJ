#include <iostream>
using namespace std;

int x[20];

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
            for(int i = 1;i * 7 <= n; i++)
                cout << 8;
            cout << endl;
        }
        else if(n % 7 == 1)
        {
            if(n == 1) cout << -1 << endl;
            else
            {
                cout << 10;
                n -= 8;
                for(int i = 1;i * 7 <= n; i++)
                    cout << 8;
                cout << endl;
            }
        }
    }
    return 0;
}
