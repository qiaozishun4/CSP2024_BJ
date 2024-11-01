#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, bool> mp;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        if (!mp[s])
        {
            mp[s] = true;
            ++cnt;
        }
    }
    cout << 52 - cnt;
    return 0;
}
