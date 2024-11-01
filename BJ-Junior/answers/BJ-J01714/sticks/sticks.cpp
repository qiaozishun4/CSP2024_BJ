#include<bits/stdc++.h>
using namespace std;
const int inf = 1e7;
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
pair<int, int> f(int n){
    pair<int, int> s;
    s.first = inf;
    s.second = inf;
    for (int x = 0;6 * x <= n;x++){
        if ((n - 6 * x) % 7 == 0){
            int y = (n - 6 * x) / 7;
            if (x + y < s.first + s.second) s = {x, y};
            else if (x + y == s.first + s.second && x > s.first) s = {x, y};
        }
    }
    return s;
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string ans = "";
        for (int i = 1;i <= 9;i++){
            auto t = f(n - a[i]);
            if (t.first == inf && t.second == inf) continue;
            string s = "";
            s += (char)(i + '0');
            for (int i = 1;i <= t.first;i++){
                s += '0';
            }
            for (int i = 1;i <= t.second;i++){
                s += '8';
            }
            if (ans == "" || s.size() < ans.size() || (s.size() == ans.size() && s < ans)) ans = s;
        }
        if (ans == "") cout << -1 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}
