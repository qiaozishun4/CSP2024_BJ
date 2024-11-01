#include <bits/stdc++.h>
#define N 1005
#define rep(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

vector<string> mp; set<pair<int, int> > s; int T, n, m, k;

bool check(int x, int y, int d) { // valid place
    if (d == 0) y++;
    if (d == 1) x++;
    if (d == 2) y--;
    if (d == 3) x--;
    return (x >= 0 && x < n && y >= 0 && y < m) && mp[x][y] == '.';
}

void op(int x, int y, int d) {
    s.insert(make_pair(x, y));
    //printf("[Debug] inserted: %d %d %d\n", x+1, y+1, d);
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> T;
    while (T--) {
        bool flag = 0;
        int x, y, d, i;
        cin >> n >> m >> k >> x >> y >> d;
        x--; y--; op(x, y, d);
        for (i = 0; i < n; i++) {
            string st;
            cin >> st;
            mp.push_back(st);
        }

        i = 0;
        while (i < k) {
            while (!check(x, y, d)) {
                d = (d + 1) % 4;
                i++;
                //printf("turn right\n");
                if (i == k) {flag = 1; break;}
            }
            if (flag) break;
            if (d == 0) y++;
            if (d == 1) x++;
            if (d == 2) y--;
            if (d == 3) x--;
            op(x, y, d);
            i++;
        }
        cout << s.size() << '\n';
        s.clear(); mp.clear();
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
