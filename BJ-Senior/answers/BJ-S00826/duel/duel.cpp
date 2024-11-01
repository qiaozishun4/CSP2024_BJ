#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n, a[100010], cnt[100010];
signed main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    int maxn = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        maxn = max(maxn, cnt[a[i]]);    
    }
    cout << maxn;
    return 0;
}