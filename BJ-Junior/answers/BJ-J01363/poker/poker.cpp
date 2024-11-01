#include <iostream>
#include <string>
#include <map>
#include <bits/stdc++.h>

using namespace std;

map <string, bool> mp;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, i, ans = 52;
    string s;
    cin >> n;
    ans -= n;
    mp.clear();
    for(i = 1; i <= n; i++)
    {
        cin >> s;
        if(mp[s] == true)
        {
            ans++;
        }
        else
        {
            mp[s] = true;
        }
    }
    cout << ans << endl;
    return 0;
}
