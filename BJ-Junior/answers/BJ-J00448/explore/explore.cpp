#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d, ans;
string mp[1005];
bool flag[1005][1005];

bool check(int yy, int xx) {
    if (xx >= 1 and xx <= m and yy >= 1 and yy <= n) {
        //cout << mp[yy][xx - 1] << '\n';
        return (mp[yy][xx - 1] == '.');
    }
    //cout << "no\n";
    return 0;
}

void dfs(int xx, int yy, int dd, int p) {
    if (p > k)
        return;

    flag[xx][yy] = 1;


    int xxx = xx, yyy = yy;
    if(dd == 0)
        yyy++;
    else if (dd == 1)
        xxx++;
    else if (dd == 2)
        yyy--;
    else
        xxx--;


    //printf("%d (%d %d) ", dd, xx, yy);
    if (check(xxx, yyy)) {
        if (!flag[xxx][yyy])
            ans++;
        return dfs(xxx, yyy, dd, p + 1);
    }
    else {
        return dfs(xx, yy, (dd + 1) % 4, p + 1);
    }
}


int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1;i <= n;i++) {
            cin >> mp[i];
        }
        ans = 1;
        dfs(x, y, d, 1);
        //cout << "//";
        cout << ans << "\n";
        memset(flag, 0, sizeof(flag));
    }
    return 0;
}


/*
1
1 5 4
1 1 2
....x
*/
