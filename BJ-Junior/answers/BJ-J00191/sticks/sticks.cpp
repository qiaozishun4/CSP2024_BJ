#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e+5+5;
int inf = 0x7FFFFFFF;
int n, t;
int s[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ts(int x)
{
    int res = 0;
    while ( x > 0 )
    {
        res += s[x%10];
        x /= 10;
    }
    return res;
}
int main (  )
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );
    cin >> t;
    while ( t-- )
    {
        cin >> n;
        if ( n <= 1 )
        {
            cout << "-1" << endl;
            continue;
        }
        int ans = 1;
        while ( ts(ans) != n && ans < N*1e+3 )
        {
            ans++;
        }
        if ( ans >= N ) cout << "-1" << endl;
        else cout << ans << endl;
    }
    return 0;
}

