#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main()
{
    //freopen("poker.in", "r", stdin);
    //freopen("poker.out", "w", stdout);
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if(mp[s] != 0) continue;
        mp[s]++;
        ans++;

    }
    cout << 52-ans;
    return 0;
}
