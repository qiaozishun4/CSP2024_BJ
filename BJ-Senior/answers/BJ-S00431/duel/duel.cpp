#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];

multiset<int> se;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        se.insert(a[i]);
        set<int>::iterator it = se.begin();
        if(*it < a[i]) ans++, se.erase(it);
    }
    cout << n - ans << '\n';
    return 0;
}