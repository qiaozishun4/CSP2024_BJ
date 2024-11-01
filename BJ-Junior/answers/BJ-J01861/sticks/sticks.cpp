#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int n, a[n], m;
    int i = 0, d = 0, m = 0;
    cin >> n >> a[n];
    while(n < a[n])
    {
        a[i] = d;
        if(d == 0)
        {
            cout << m;
            i++
        }
        if(d >= 7)
        {
            m += 7;
            d -= 7;
        }
        else if(d == 6)
        {
            d -= 6;
            m += 0;
        }
        else if(d == 5)
        {
            d -= 5;
            m += 3
        }
        else if(d == 4)
        {
            d -= 4;
            m += 4;
        }
        else if(d == 3)
        {
            d -= 3;
            m += 7;
        }
        else if(d == 2)
        {
            d -= 2;
            m += 1;
        }
        else
        {
            cout << -1;
        }
    }
    return 0;
}
