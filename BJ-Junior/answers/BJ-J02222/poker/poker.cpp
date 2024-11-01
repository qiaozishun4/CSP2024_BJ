#include <bits/stdc++.h>
using namespace std;
map<string, int> maps;
int n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        maps[s]++;
    }
    cout << (52 - maps.size());
    return 0;
}
