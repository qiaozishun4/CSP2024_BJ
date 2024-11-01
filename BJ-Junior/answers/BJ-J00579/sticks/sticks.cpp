#include <bits/stdc++.h>
using namespace std;
int sticks1[15] = {6, 2, 5, 4, 6, 3, 7};
int sticks2[15] = {0, 1, 2, 4, 6, 7, 8};
int T, n;
string ans;
bool flag = 0;
string minstr(string x, string y) {
    if(x.size() != y.size()) {
        if(x.size() < y.size())
            return x;
        return y;
    }
    for(int i = 0;i < x.size();i++) {
        if(x[i] == y[i]) continue;
        if(x[i] < y[i])
            return x;
        return y;
    }
    return x;
}
void dfs(int step, int num, string s) {
    if(num == 0) {
        ans = minstr(ans, s);
        flag = true;
        return ;
    }
    for(int i = 0;i <= 6;i++) {
        if(i == 0 && step == 0)
            continue;
        if(num >= sticks1[i]) {
            string s1 = s + char(sticks2[i] + '0');
            dfs(step + 1, num - sticks1[i], s1);
        }
    }
}
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        if(n <= 20) {
            flag = 0;
            ans = "99999999999999999999999999999999999999999999999999999999";
            dfs(0, n, "");
            if(!flag || !n)
                cout << -1 << endl;
            else
                cout << ans << endl;
        }
        else if(n % 7 == 0) {
            for(int i = 1;i <= n / 7;i++)
                cout << 8;
            cout << endl;
        }
        else if((n - 1) % 7 == 0) {
            cout << 10;
            for(int i = 1;i <= ((n - 1) / 7) - 1;i++)
                cout << 8;
            cout << endl;
        }
        else if((n - 2) % 7 == 0) {
            cout << 1;
            for(int i = 1;i <= (n - 2) / 7;i++)
                cout << 8;
            cout << endl;
        }
        else if((n - 3) % 7 == 0) {
            if(n == 10)
                cout << 22 << endl;
            else {
                cout << 200;
                for(int i = 1;i <= ((n - 3) / 7) - 2;i++)
                    cout << 8;
                cout << endl;
            }
        }
        else if((n - 4) % 7 == 0) {
            cout << 20;
            for(int i = 1;i <= ((n - 4) / 7) - 1;i++)
                cout << 8;
            cout << endl;
        }
        else if((n - 5) % 7 == 0) {
            cout << 2;
            for(int i = 1;i <= (n - 5) / 7;i++)
                cout << 8;
            cout << endl;
        }
        else if((n - 6) % 7 == 0) {
            cout << 6;
            for(int i = 1;i <= ((n - 6) / 7);i++)
                cout << 8;
            cout << endl;
        }
    }
    return 0;
}
