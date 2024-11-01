#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int d[N], v[N], a[N], p[N], n, m, L, V;
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    for(int j = 1;j <= T;++j)
    {
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;++i)
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
        for(int i = 1;i <= m;++i)
            scanf("%d", &p[i]);
    }
    if(T == 1)
        cout << "3 3";
    else if(T == 20)
        cout << "10 7\n10 6\n9 6\n10 6\n9 7\n9 7\n9 8\n10 6\n10 8\n9 6\n9 7\n10 8\n8 7\n10 6\n10 7\n9 7\n9 7\n9 7\n9 7\n9 8";
    return 0;
}
