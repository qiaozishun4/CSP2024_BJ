#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        int a[n + 1], b[2001];
        memset(b, 0, sizeof(b));
        int maxn = -1e9;
        for(int i = 1; i <= n; i ++)
        {
            cin >> a[i];
            b[a[i]] ++;
            maxn = max(a[i], maxn);
        }
        int ans = 0;
        for(int i = 1; i <= maxn; i ++)
            if(b[i])
               ans += (b[i] - 1) * i;
        cout << ans << endl;
    }
    return 0;
}