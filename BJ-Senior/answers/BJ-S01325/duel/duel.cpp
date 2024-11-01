#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int r[N], vis[N];
map<int, int> m;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out","w", stdout);
    int n, ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> r[i];
    for(int i = 1;i <= n;i++) m[r[i]]++;
    int last = 0;
    bool f = 1;
    for(auto t : m)
    {
        int x = t.second;
        if(f == 1)
        {
            ans = x;
            f  = 0;
            continue;
        }
        ans = max(ans - x, 0);
        ans += x;
    }
    cout << ans;
    return 0;
}
