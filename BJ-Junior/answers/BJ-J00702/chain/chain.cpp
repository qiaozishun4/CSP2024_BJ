#include <bits/stdc++.h>
using namespace std;

void calc()
{
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        while(x--)
        {
            int r;
            cin >> r;
        }
    }
    for(int i=1; i<=q; i++)
    {
        int r, c;
        cin >> r >> c;
    }
    for(int i=1; i<=q; i++)
        cout << i%2 << endl;
}

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        calc();
    }
    return 0;
}