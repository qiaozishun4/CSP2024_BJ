#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<int, string> mp;

string min1(string a, string b) {
    if (a.size() > b.size()) {
        return b;
    } else if (a.size() < b.size()) {
        return a;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i]) {
            return a;
        }
    }
    return b;
}

string change(string a) {
    string s = a;
    int i = 0;
    while (s[i] == '6' && i < s.size()) {
        s[i] = '0';
        i++;
    }
    return s;
}

void f(int n) {
    string ans;
    for (int i = 9; i <= n; i++) {
        string ans;
        for (int j = 2; j < i / 2 + 1; j++) {
            string tmp1 = mp[j];
            string tmp2 = mp[i - j];
            if (ans.size() == 0) {
                ans = tmp1 + tmp2;
            }
            ans = min1(ans, min1(tmp1 + change(tmp2), tmp2 + change(tmp1)));
        }
        mp[i] = ans;
    }
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    mp[2] = "1";
    mp[3] = "7";
    mp[4] = "4";
    mp[5] = "2";
    mp[6] = "6";
    mp[7] = "8";
    mp[8] = "10";
    f(1000);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << -1 << endl;
        } else if (n % 7 == 0) {
            string ans;
            while(n > 0) {
                ans += "8";
                n -= 8;
            }
            cout << ans << endl;
        } else if (n % 7 == 1) {
            string ans = 0;
            while(n > 8) {
                ans += "8";
                n -= 8;
            }
            ans = "16" + ans;
            cout << ans << endl;
        } else {
            cout << mp[n] << endl;
        }
    }
    return 0;
}