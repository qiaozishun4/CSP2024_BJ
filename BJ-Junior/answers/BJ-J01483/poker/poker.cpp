#include <iostream>
#include <map>
using namespace std;

int n, cnt = 0;
map <string, int> mp;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if(mp[s] == 0) mp[s] = 1, cnt++;
    }
    cout << 52 - cnt << endl;
    return 0;
}
