#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        m[s] = 1;
    }
    int ans = m.size();
    cout << 52 - ans << endl;
    return 0;
}