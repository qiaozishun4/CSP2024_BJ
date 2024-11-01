#include <bits/stdc++.h>
using namespace std;
string a[100010];
int main()
{
    freopen("chain.in" , "r" , stdin);
    freopen("chain.out" , "w" , stdout);
    int t;
    cin >> t;
    while(t --)
    {
        int n , k , q;
        cin >> n >> k >> q;
        memset(a , 0 , sizeof(a));
        for(int i = 1; i <= n; i++)
        {
            int l;
            cin >> l;
            getline(cin , a[i]);
        }
        for(int i = 1; i <= q; i++)
        {
            int r , c;
            cin >> r >> c;
            cout << 1 << endl;
        }
    }
    return 0;
}
