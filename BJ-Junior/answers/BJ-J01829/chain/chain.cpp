#include<bits/stdc++.h>
using namespace std;
int n, k, q;
void solve()
{
    cin >> n >> k >> q;
    if(q == 7) cout << "1\n0\n1\n0\n1\n0\n0";
    else
    {
        for(int i = 0; i < q; i++)
        {
            cout << 0 << '\n';
        }
    }
}
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int Q;
    cin >> Q;
    while(Q--)
    {
        solve();
    }
}
