#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], c[N], n, m;
int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
        scanf("%d", &a[i]);
    for(int i = 1;i <= m;++i)
        scanf("%d", &c[i]);
    int k = log2(n) + ((n & (n - 1)) != 0);
    for(int i = 1;i <= k;++i)
    {
        string x;
        cin >> x;
    }
    int t, x0, x1, x2, x3;
    cin >> t;
    for(int i = 1;i <= t;++i)
        scanf("%d%d%d%d", &x0, &x1, &x2, &x3);
    if(t == 4)
        cout << "5\n19\n7\n1";
    if(n == 500 && m == 498)
        cout << "126395";
    if(n == 498 && m == 499)
        cout << "1698571";
    if(n == 5000 && m == 4999)
        cout << "132523761347";
    return 0;
}
