#include <algorithm>
#include <iostream>
#include <cstdio>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int NR = 1e5 + 5;
int n;
int a[NR];
pii p[NR];
int dp[NR];
bool flag[NR];
int main()
{
    //freopen("//home//csps//duel4.in", "r", stdin);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i].fi;
        p[i].se = i;
        a[i] = p[i].fi;
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    int j = 1;
    for(int i = 1; i <= n; i++)
    {
        while(a[j] <= a[i] && j < n) j++;
        if(a[j] > a[i]) j++, ans++;
    }
    //cout << ans << endl;
    cout << n - ans << endl;
    return 0;
}
