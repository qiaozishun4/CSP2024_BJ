#include <bits/stdc++.h>

using namespace std;
set<string> s;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string t;
        cin >> t;
        s.insert(t);
    }
    cout << 52 - s.size() << endl;
    return 0;
}
//Y#C*GF@24
