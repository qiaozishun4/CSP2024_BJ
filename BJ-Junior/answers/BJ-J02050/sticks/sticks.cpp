#include <bits/stdc++.h>
using namespace std;
int a[11] = {6,2,5,5,4,5,6,3,7,6};
void solve()
{
    long long n;
    cin >> n;
    if(n == 1 || n == 0)
    {
        cout << "-1" << endl;
    }
    else if(n == 2)
    {
        cout << 1 << endl;
    }
    else if(n == 3)
    {
        cout << 7 << endl;
    }
    else if(n == 4)
    {
        cout << 4 << endl;
    }
    else if(n == 5)
    {
        cout << 2 << endl;
    }
    else if(n == 6)
    {
        cout << 6 << endl;
    }
    else
    {
        if(n % 7 == 0)
        {
            for(int i = 1;i <= n / 7;i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else
        {
            n -= 7;
            if(n <= 11)
            {
                int x = n / 6;
                for(int i = 0;i <= 10;i++)
                {
                    if(a[i] == n % 6)
                    {
                        cout << i;
                        break;
                    }
                }   
                for(int i = 1;i <= x;i++)
                {
                    cout << 0;
                }
                cout << 8 << endl;
            }
            else
            {
                int x = n / 7;
                for(int i = 0;i <= 10;i++)
                {
                    if(a[i] == n % 7)
                    {
                        cout << i;
                        break;
                    }
                }
                for(int i = 1;i <= x + 1;i++)
                {
                    cout << 8;
                }   
                cout << endl;
            }
        }
    }
}
int main()
{
    freopen("sticks.in" , "r" , stdin);
    freopen("sticks.out" , "w" , stdout);
    int T;
    cin >> T;
    for(int i = 1;i <= T;i++)
    {
        solve();
    }
    return 0;
}