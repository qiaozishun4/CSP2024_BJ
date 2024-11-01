#include <bits/stdc++.h>
using namespace std;
long long a[200005], c[1000005];
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        memset(c, 0, sizeof(c));
        int n;
        cin >> n;
        long long ans = 0;
        for(int i = 1; i <= n;i++)
        {
            cin >> a[i];
            c[a[i]]++;
            if(c[a[i]] % 2 == 0)
            {
                ans += a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
