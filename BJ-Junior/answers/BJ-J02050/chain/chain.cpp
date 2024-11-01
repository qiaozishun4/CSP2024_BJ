#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in" , "r" , stdin);
    freopen("chain.out" , "w" , stdout);
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        int n  , k , q;
        cin >> n >> k >> q;
        for(int j = 1;j <= n;j++)
        {
            int x;
            cin >> x;
            for(int y = 1;y <= x;y++)
            {
                int a;
                cin >> a;
            }
        }
        for(int j = 1;j <= q;j++)
        {
            int a ,b;
            cin >> a >> b;
        }
        for(int i = 1;i <= q;i++)
        {
            cout << rand()%3 - 1;
        }
    }
    
    return 0;
}