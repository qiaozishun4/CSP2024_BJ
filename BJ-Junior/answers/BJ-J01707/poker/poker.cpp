#include <iostream>
#include <map>
using namespace std;

int n, cnt;
map<string, bool> mp;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        if (!mp[s])
        {
            ++cnt;
            mp[s] = true;
        }
    }
    cout << 52 - cnt;
    return 0;
}
