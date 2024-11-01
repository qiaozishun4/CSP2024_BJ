#include <bits/stdc++.h>
using namespace std;

int T;
int n, k , q, last1;
vector<int> g[100010];
bool ok[200010];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("chain.in","r", stdin);
    freopen("chain.out","w", stdout);
    cin >> T;
    while(T--)
    {
        memset(ok, 0, sizeof(ok));
        cin >> n >>k >> q;
        int cur = 0;
        for(int i = 1; i<= n; i++)
        {
            g[i].clear();
            int l;
            cin >> l;
            last1 = -2e5;
            for(int j = 1; j <= l; j++)
            {
                int x;
                cin >> x;
                g[i].push_back(x);
                if(j - last1 + 1 <= k) ok[x] = true;
                if(x == 1)
                    last1 = j;
            }
        }
        while(q--)
        {
            int r, c;
            cin >> r >> c;
            cout << ok[c] << endl;
        }
    }
    return 0;
}
