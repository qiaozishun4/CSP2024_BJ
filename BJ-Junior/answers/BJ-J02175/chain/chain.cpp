#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
ll n, k, q;
bool dp[200005];
vector <ll> a[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    srand(time(NULL));
    mt19937 rnd(rand());
    // cout << t << endl;
    for(int i = 1; i <= t; i++)
    {
        cin >> n >> k >> q;
        // cout << i << " : " << n << " " << k << " " << q << endl;
        for(int i = 1; i <= n; i++)
        {
            ll l;
            cin >> l;
            ll cnt = 0;
            bool f = 0;
            for(int j = 1; j <= l; j++)
            {
                ll x;
                cin >> x;
                if(cnt >= k)
                {
                    f = 0;
                    cnt = 0;
                }
                if(f)
                {
                    cnt++;
                    dp[x] = 1;
                }
                if(x == 1)
                {
                    f = 1;
                    cnt = 1;
                }
            }
        }
        while(q--)
        {
            ll r, c;
            cin >> r >> c;
            if(r == 1)
                cout << dp[c] << "\n";
            else
                cout << rnd() % 2 << "\n";
        }
    }
    return 0;
}