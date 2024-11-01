#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
string s = "";

void dfs(string x, int sum) {
    if (sum > n) return;
    if (sum == n) {
        if (s.size() == 0) {
            s = x;
        }
        if (x.size() < s.size()) {
            s = x;
            return;
        }
        if (x < s) {
            s = x;
            return;
        }
        return;
    }
    if (x.size() > 0) dfs(x + '0', sum + 6);
    dfs(x + '1', sum + 2);
    dfs(x + '2', sum + 5);
    dfs(x + '4', sum + 4);
    dfs(x + '6', sum + 6);
    dfs(x + '7', sum + 3);
    dfs(x + '8', sum + 7);
}

int main() {
freopen("sticks.in", "r", stdin);
freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        if (n <= 50) {
            s = "";
            dfs("", 0);
            cout << (s.size() == 0 ? "-1" : s) << endl;
            continue;
        }
        if (n % 7 == 0) {
            for (int i = 1; i <= n / 7; i++) cout << 8;
            cout << endl;
            continue;
        }
        if (n % 7 == 1) {
            cout << -1;
            cout << endl;
            continue;
        }
        cout << -1 << endl;
    }
    return 0;
}
