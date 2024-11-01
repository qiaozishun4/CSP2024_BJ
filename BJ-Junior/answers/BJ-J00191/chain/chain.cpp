#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e+5+5;
int inf = 0x7FFFFFFF;
int t;
int n, q, k, l[N], ans = 0;
string s[N][N], last;
bool flag = 0;
int main (  )
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );
    cin >> t;
    while ( t-- )
    {
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i];
            for (int j = 1; j <= l[i]; j++)
            {
                cin >> s[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            flag = 0;
            for (int j = 1; j <= l[i]; j++)
            {
                for (int m = 1; m <= s[i][j].length() - k; m++)
                {
                    if ( i == 1 )
                    {
                        if ( s[i][j][m] == '1' )
                        {
                            last = s[i][j].substr(m, k);
                            flag = 1;
                            break;
                        }
                    }
                    else
                    {
                        if ( s[i][j].front() == last.back() )
                        {
                            last = s[i][j].substr(m, k);
                            flag = 1;
                            break;
                        }
                    }
                    if (flag) break;
                }
                if (flag) break;
            }
            ans++;
            if (ans == q) break;
        }
        if ( ans >= q ) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}

