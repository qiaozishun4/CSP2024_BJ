#include<bits/stdc++.h>
using namespace std;
map<int, int> m;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, x, y, ans = 0;
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++){
        cin >> x;
        m[x]++;
    }
    x = m.begin()->second;
    for (auto it = ++m.begin(); it != m.end(); it++){
        //cout << it->first << ' ' << it->second << endl;
        y = it->second;
        ans -= min(x, y);
        x -= min(x, y);
        x += y;
    }
    cout << ans;
    return 0;
}
