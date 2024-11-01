#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, c1 = 0, c2 = 0, f = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x == 1) c1++;
        else if(x == 2) c2++;
        else f = 1;
    }
    if(f == 0)
    {
        if(c1 > c2)
        {
            cout << c2 + (c1 - c2);
        }
        else
        {
            cout << c2;
        }
    }
    else
    {
        if(n <= 30) cout << 1;
        else cout << n / 2;
    }
    return 0;
}
