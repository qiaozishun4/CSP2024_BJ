#include <iostream>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 1;i<=t;i++)
    {
        int n;
        cin >> n;
        if(n % 7 == 0)
        {
            for(int j = 1;j<=n / 7;j++)
                cout << 8;
            cout << endl;
        }
        if(n % 7 == 1)
        {
            for(int j = 1;j<=(n - 8) / 7;j++)
                cout << 8;
            cout << 44 << endl;
        }
    }
    return 0;
}
