#include <bits/stdc++.h>
using namespace std;

int n, ans;
map<int, int> mp;

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++){
        auto p = mp.begin(); int k = (it->second);
        while (p != it){
            if ((p->second) <= k){
                k -= (p->second);
                p = mp.erase(p);
            }
            else {
                (p->second) -= k;
                break;
            }
        }
    }
    for (pair<int, int> p : mp){
        ans += p.second;
    }
    cout << ans << endl;
    return 0;
}
