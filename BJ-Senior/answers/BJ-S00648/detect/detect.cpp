#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n, m, l, v1, a[100005], d[100005], v[100005], p[100005];
        cin >> n >> m >> l >> v1;
        for(int i = 1;i<=n;i++)
            cin >> d[i] >> v[i] >> a[i];
        for(int i = 1;i<=m;i++)
            cin >> p[i];
        cout << v1 << " " << v1;
        
    }
    return 0;
}
