#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n;
set<string> se;

signed main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        se.insert(s);
    }
    cout << (52 - se.size());

    return 0;
}