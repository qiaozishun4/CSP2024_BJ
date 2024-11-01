#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

bool die[N];
int r[N];

priority_queue < int, vector <int>, greater<int> > q;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    bool flg = 1;
    int n, tt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", r + i);
        if (r[i] != 1 && r[i] != 2)
            flg = 0;
    }
    if (flg) {
        for (int i = 1; i <= n; i++)
            if (r[i] == 1)
                tt++;
        cout << max(tt, n - tt);
        return 0;
    }
    sort(r + 1, r + n + 1);
    for (int i = 1; i <= n; i++) {
        q.push(r[i]);
        if (q.top() < r[i]) {
            q.pop();
            tt++;
        }
    }
    cout << n - tt;
    return 0;
}
