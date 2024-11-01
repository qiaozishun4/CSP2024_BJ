#include <iostream>
using namespace std;
#define ll long long
ll t, n, mini = 2e9;
string nnum;
ll num[20] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ll strInt(string str) {
    ll ans = 0;
    ll mid = 1;
    for(int i = str.size() - 1; i >= 0; i--) {
        ans += (int){str[i] - '0'} * mid;
        mid *= 10;
    }
    return ans;
}
void Dfs(ll m) {
    for(int i = 0; i <= 9; i++) {
        if(i != 3 && i != 5) {
            if(i == 0 && m == n) {
                continue;
            }
            if(m - num[i] == 0) {
                nnum += i + '0';
                cout << nnum << endl;
                mini = min(strInt(nnum), mini);
                nnum = "";
                m = n;
                return;
            }
            if(m - num[i] < 0) {
                continue;
            }
            nnum += i + '0';
            Dfs(m - num[i]);
        }

    }
}
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n;
        nnum = "";
        mini = 2e9;
        for(int i = 1; i <= 9; i++) {
            if(n - num[i] == 0) {
                mini = i;
                break;
            }
        }
        if(mini != 2e9) {
            cout << mini << endl;
            continue;
        }
        Dfs(n);
        if(mini == 2000000000) {
            cout << -1 << endl;
            continue;
        }
        cout << mini;
    }

    return 0;
}
