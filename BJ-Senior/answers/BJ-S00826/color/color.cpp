#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define int long long
using namespace std;
int a[200010], h[1000010], s[200010];
bool rb[200010];
int msc;
void dfs(int stp, int n, int lr, int lb, int sco)
{
    if(stp > n)
    {
        msc = max(msc, sco);
        return;
    }
    //if(sco + s[stp] < msc) return;
    rb[stp] = 0;
    int t = sco;
    if(lr != -1 && a[lr] == a[stp]) t += a[lr];
    dfs(stp + 1, n, stp, lb, t);
    rb[stp] = 1;
    t = sco;
    if(lb != -1 && a[lb] == a[stp]) t += a[lb];
    dfs(stp + 1, n, lr, stp, t);
}
signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        memset(h, 0, sizeof(h));
        memset(s, 0, sizeof(s));
        for(int i = 1; i <= n; i++) cin >> a[i];
        memset(rb, 0, sizeof(rb));
        dfs(1, n, -1, -1, 0);
        cout << msc << "\n";
        msc = 0;
    }
    return 0;
}