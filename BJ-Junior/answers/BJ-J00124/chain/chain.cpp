#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5+5;

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;cin >> t;
    while(t--)
    {
        int a[mx], b[mx];
        int n,k,q;
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++)
        {
            int temp, a[mx];
            cin >> temp;
            while(temp--)
            {
                cin >> a[temp];
            }
        }
        for(int i = 1; i <= q; i++)
        {
            int x, y;
            cin >> x >> y;
            cout<<y/x << endl;
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
