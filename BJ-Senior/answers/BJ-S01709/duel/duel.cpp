#include<bits/stdc++.h>
using namespace std;
constexpr int N = 100005;
int n, a[N], q[N], h, t;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    q[++t] = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(a[q[h + 1]] < a[i])
            ++h;
        q[++t] = i;
    }
    cout << t - h << '\n';
    return 0;
}
