#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

string res = "";
int sz[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

bool cmp(string x, string y)
{
    if (res.empty())
        return 1;
    if (x.size() > y.size())
        return 1;
    if (x.size() < y.size())
        return 0;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] > y[i])
            return 1;
        else if (x[i] < y[i])
            return 0;
    }
}

void dfs(int m, string x)
{
    if (x[0] == '0' || m < 0)
        return;
    if (m == 0) {
        if (cmp(res, x))
            res = x;
        return;
    }
    for (int i = 0; i < 10; i++) {
        dfs(m - sz[i], x + (char)((int)'0' + i));
    }
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        res.clear();
        int n;
        cin >> n;
        dfs(n, "");
        if (!res.empty()) {
            cout << res;
        } else {
            cout << -1;
        }
        cout << '\n';
    }
    return 0;
}
