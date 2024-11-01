#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1;
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        int S[MAXN];
        int r[MAXN], c[MAXN];
        for(int i=1; i<=n; i++)
        {
            int l;
            cin >> l;
            for(int j=1; j<=l; j++) cin >> S[j];
        }
        for(int i=1; i<=q; i++) cin >> r[i] >> c[i];
        cout << i%2 << endl;
    }
    return 0;
}