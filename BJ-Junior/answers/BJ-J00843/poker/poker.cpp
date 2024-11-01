#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> mp;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (mp[s] == 0)
        {
            cnt++;
            mp[s] = 1;
        }
    }
    cout << 52 - cnt << '\n';
    return 0;
}
