#include <bits/stdc++.h>
using namespace std;
int n;
string a[60];
map <string, int> mp;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    cout << max(0, 52 - (int)mp.size());
    return 0;
}

















