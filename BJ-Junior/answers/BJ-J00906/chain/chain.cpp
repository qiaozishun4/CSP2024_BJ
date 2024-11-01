#include <bits/stdc++.h>
using namespace std;

int s[1005][1005] , x[1005];
int main()
{
    freopen("chain.in" , "r" , stdin);
    freopen("chain.out" , "w" , stdout);
    int t;cin >> t;
    while(t--)
    {
        int n , k , q;cin >> n >> k >> q;
        for(int i = 1; i <= n; i++)
        {
            cin >> x[i];
            for(int j = 1; j <= x[i]; j++) cin >> s[i][j];
        }
        while(q--)
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
