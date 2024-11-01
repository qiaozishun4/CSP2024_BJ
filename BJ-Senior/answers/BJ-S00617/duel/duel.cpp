#include <bits/stdc++.h>

using namespace std;

int n, a;
map <int, int> mp;
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        mp[a]++;
    }
    int ag = 0;
    for (auto it : mp)
    {
        ag = max(0, ag - it.second);
        ag += it.second;
    }
    cout << ag << endl;
    return 0;
}