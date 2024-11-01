#include <bits/stdc++.h>
using namespace std;
int t, n, a[11], g, sum;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    a[0] = 6;
    a[1] = 2;
    a[2] = 5;
    a[4] = 4;
    a[6] = 6;
    a[7] = 3;
    a[8] = 7;
    cin >> t;
    while(t--)
    {
        sum = 0;
        cin >> n;
        if(n < 2)
        {
            cout << -1 << endl;
            continue;
        }
        if(n%7==0)
        {
            for (int i = 1; i <= n/7; i++)
            {
                cout << '8';
            }
            cout << endl;
            continue;
        }
        if(n%7==1)
        {
            cout << "10";
            for (int i = 1; i <= (n-8)/7; i++)
            {
                cout << '8';
            }
            cout << endl;
            continue;
        }
        else
        {
            g = n/7+1;
            for(int k = 1;k <= g*9; k++)
            {
                for (int i = 1;i <= g; i++)
                {
                    for (int j = k+i+1; j <= 8; j++)
                    {
                        if(i==1 && j==0)
                        {
                            continue;
                        }
                        if(a[j] == 0)
                        {
                            continue;
                        }
                        sum+=a[j];
                        break;
                    }
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
