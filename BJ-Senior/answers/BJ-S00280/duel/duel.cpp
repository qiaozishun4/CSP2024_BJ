#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 5;

int a[N];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == a[1]) ans++;
    cout << ans;
    return 0;
}
