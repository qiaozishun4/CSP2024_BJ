#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e+5+5;
int inf = 0x7FFFFFFF;
int n, ans = 0;
string s;
bool a[7][17];
int main (  )
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );
    cin >> n;
    for (int i = 1, f, l; i <= n ; i++)
    {
        cin >> s;
        if ( s[0] == 'D' ) f = 1;
        else if ( s[0] == 'C' ) f = 2;
        else if ( s[0] == 'H' ) f = 3;
        else if ( s[0] == 'S' ) f = 4;
        if ( s[1] >= '2' && s[1] <= '9' ) l = s[1] - '0';
        else if ( s[1] == 'A' ) l = 1;
        else if ( s[1] == 'T' ) l = 10;
        else if ( s[1] == 'J' ) l = 11;
        else if ( s[1] == 'Q' ) l = 12;
        else if ( s[1] == 'K' ) l = 13;
        a[f][l] = true;
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            if ( a[i][j] == false ) ans++;
        }
    }
    cout << ans;
    return 0;
}

