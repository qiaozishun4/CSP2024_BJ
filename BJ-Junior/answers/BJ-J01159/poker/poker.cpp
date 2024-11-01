#include<bits/stdc++.h>
#define int long long
using namespace std;
bool f[200][200];
signed main()
{

    freopen("poker.in" , "r" , stdin);
    freopen("poker.out" , "w" , stdout);

    int n;
    cin >> n;
    int ans = 52;
    for (int i = 1 ; i <= n ; i++)
    {
        char a , b;
        cin >> a >> b;
        if (!f[a][b])
        {
            ans--;
        }
        f[a][b] = 1;
    }
    cout << ans << endl;
    return 0;
}
