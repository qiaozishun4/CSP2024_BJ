#include<bits/stdc++.h>
using namespace std;
unordered_map<char, bool> a_d;
unordered_map<char, bool> a_c;
unordered_map<char, bool> a_h;
unordered_map<char, bool> a_s;
string num = "A23456789TJQK";
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, i, ans = 0, m = num.size();
    string s;
    for(i = 0; i < m; i++) {
        a_d[num[i]] = 0;
    }
    for(i = 0; i < m; i++) {
        a_c[num[i]] = 0;
    }
    for(i = 0; i < m; i++) {
        a_h[num[i]] = 0;
    }
    for(i = 0; i < m; i++) {
        a_s[num[i]] = 0;
    }
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> s;
        switch(s[0]) {
            case 'D': a_d[s[1]] = true; break;
            case 'C': a_c[s[1]] = true; break;
            case 'H': a_h[s[1]] = true; break;
            case 'S': a_s[s[1]] = true; break;
        }
    }
    for(i = 0; i < m; i++) {
        if(a_d[num[i]] == 0) {
            ans++;
        }
    }
    for(i = 0; i < m; i++) {
        if(a_c[num[i]] == 0) {
            ans++;
        }
    }
    for(i = 0; i < m; i++) {
        if(a_h[num[i]] == 0) {
            ans++;
        }
    }
    for(i = 0; i < m; i++) {
        if(a_s[num[i]] == 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
