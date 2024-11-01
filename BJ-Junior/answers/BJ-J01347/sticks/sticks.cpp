#include <bits/stdc++.h>
using namespace std;
int sticks[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ind   [] = {8, 0, 6, 9, 2, 3, 5, 4, 7, 1};
int t, n, mlen;
string ans;
string op(string ans) {
    bool flag = true;
    string res;
    for(char c : ans) {
        if(c != '0' || !flag) {
            res += c;
            flag = false;
        }
    }
    return res;
}
string dfs(string a, int x, int s) {
    if(s == 0) {
        string rtn(100000-a.size(), '0');
        rtn += a;
        mlen = min(mlen, (int)a.size());
        return rtn;
    }
    string ans(100000, 'X');
    if(a.size() > mlen) return ans;
    for(int x = 0; x <= 9; x++) {
        int i = ind[x];
        if(sticks[i] + (mlen-1) * 7 < n) break;
        if(s - sticks[i] >= 0) ans = min(ans, dfs(a + char(i+'0'), i, s-sticks[i]));
    }
    return ans;
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while(t--) {
        ans.clear();
        ans = string(100000, 'X');
        cin >> n;
        mlen = n / 2 + 1;
        string e;
        for(int x = 1; x <= 9; x++) {
            int i = ind[x];
            if(n - sticks[i] >= 0 && i != 0) ans = min(ans, dfs(e + char(i+'0'), i, n-sticks[i]));
        }
        if(ans == string(100000, 'X')) puts("-1");
        else cout << op(ans) << endl;
    }
    return 0;
}