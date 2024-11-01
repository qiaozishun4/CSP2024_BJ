#include <bits/stdc++.h>
using namespace std;
int a[9];
int cnt[9];
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        a[0] = 6;
        a[1] = 2;
        a[2] = 5;
        a[3] = 5;
        a[4] = 4;
        a[5] = 5;
        a[6] = 6;
        a[7] = 3;
        a[8] = 7;
        a[9] = 6;
        int x;
        cin >> x;
        if(x < 2)
        {
            cout << -1 << endl;
            continue;
        }
        if(x <= 7)
        {
            for(int i = 0; i <= 9; i++)
            {
                if(x == a[i])
                {
                    cout << i << endl;
                    break;
                }
            }
        }else{
            while(x != 0)
            {
                x -= 7;
                cout << 8;
            }
        }
    }
    return 0;

}
