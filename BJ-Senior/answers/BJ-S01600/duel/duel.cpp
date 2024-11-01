#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;

int n, r[N], ans;
queue <int> q;

void insert()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> r[i];
}

void work()
{
    insert();
    ans = n;
    sort(r + 1, r + n + 1);
    for(int i = 1; i <= n; i++)
        if(q.empty() || r[i] <= q.front())
            q.push(r[i]);
        else
            ans--, q.pop(), q.push(r[i]);
    cout << ans << endl;
}

signed main()
{
    freopen("duel.out", "w", stdout);
    freopen("duel.in", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    work();
}