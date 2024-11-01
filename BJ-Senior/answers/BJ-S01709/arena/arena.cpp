#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 105;
ll T, n, m, k, ta[N], a[N], c[N], x[N];
bool d[N][N];
int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> ta[i];
    for(int i = 1; i <= m; ++i)
        cin >> c[i];
    for(; (1 << k) < n; ++k);
    for(int i = 1; i <= k; ++i)
        for(int j = 1; j <= (1 << (k - i)); ++j)
        {
            char C;
            cin >> C;
            d[i][j] = C - '0';
        }
    cin >> T;
    while(T--)
    {
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        for(int i = 1; i <= n; ++i)
            a[i] = ta[i] ^ x[i & 3];
        ll ans = 0;
        for(int i = 1; i <= m; ++i)
        {
            if(c[i] == 1)
                ans ^= i;
            else if(c[i] == 2)
            {
                ans ^= i * ((d[1][1] ^ (a[d[1][1] + 1] < 1)) + 1);
            }
            else if(c[i] == 3)
            {
                int v1 = 1, v2 = 2, v3 = 3, v4 = 4, tmp = a[4], zs = 0;
                bitset<10> b;
                for(a[4] = 1; a[4] < 5; ++a[4])
                {
                    if(d[1][1])
                        swap(v1, v2);
                    if(d[1][2])
                        swap(v3, v4);
                    if(a[v1] < 1)
                        v1 = v2;
                    if(a[v3] < 1)
                        v3 = v4;
                    if(d[2][1])
                        swap(v1, v3);
                    if(a[v1] < 2)
                        v1 = v3;
                    b.set(v1);
                }
                a[4] = tmp;
                for(int i = 1; i <= 4; ++i)
                    if(b[i])
                        zs += i;
                ans ^= i * zs;
            }
            else if(c[i] == 4)
            {
                int v1 = 1, v2 = 2, v3 = 3, v4 = 4;
                if(d[1][1])
                    swap(v1, v2);
                if(d[1][2])
                    swap(v3, v4);
                if(a[v1] < 1)
                    v1 = v2;
                if(a[v3] < 1)
                    v3 = v4;
                if(d[2][1])
                    swap(v1, v3);
                if(a[v1] < 2)
                    v1 = v3;
                ans ^= i * v1;
            }
            else if(c[i] == 8)
            {
                int v1 = 1, v2 = 2, v3 = 3, v4 = 4, v5 = 5, v6 = 6, v7 = 7, v8 = 8;
                if(d[1][1])
                    swap(v1, v2);
                if(d[1][2])
                    swap(v3, v4);
                if(a[v1] < 1)
                    v1 = v2;
                if(a[v3] < 1)
                    v3 = v4;
                if(d[2][1])
                    swap(v1, v3);
                if(a[v1] < 2)
                    v1 = v3;

                if(d[1][3])
                    swap(v5, v6);
                if(d[1][4])
                    swap(v7, v8);
                if(a[v5] < 1)
                    v5 = v6;
                if(a[v7] < 1)
                    v7 = v8;
                if(d[2][2])
                    swap(v5, v7);
                if(a[v5] < 2)
                    v5 = v7;

                if(d[3][1])
                    swap(v1, v5);
                if(a[v1] < 3)
                    v1 = v5;
                ans ^= i * v1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
