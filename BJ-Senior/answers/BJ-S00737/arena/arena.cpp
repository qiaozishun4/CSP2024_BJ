#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+3;
typedef long long ll;
int ya[N], a[N], c[N];
bool d[20][N];
int X[4];
unordered_set<int> s_cw[N];

int main()
{
    ios::sync_with_stdio(false);
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> ya[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> c[i];
    }
    int K = (int)ceil(log2(n));
    for(int i = 1; i <= K; i++)
    {
        for(int j = 1; j <= (1<<(K-i)); j++)
        {
            char tmp;
            cin >> tmp;
            d[i][j] = tmp - '0';
        }
    }
    int T;
    cin >> T;
    while(T--)
    {
        cin >> X[0] >> X[1] >> X[2] >> X[3];
        for(int i = 1; i <= n; i++)
        {
            a[i] = ya[i] ^ X[i & 3];
            //cout << a[i] << " ";
        }
        //cout << endl;
        ll ans = 0;
        for(int i = 1; i <= m; i++)
        {
            int k = (1<<(int)ceil(log2(c[i]))), l = 0;
            for(int j = 1; j <= k; j++)
            {
                s_cw[j].clear();
                s_cw[j].insert(j);
            }
            while(k != 1)
            {
                k >>= 1;
                l++;
                for(int j = 1; j <= k; j++)
                {
                    int lz = (j<<1) - 1 + d[l][j];
                    int dt = (d[l][j] ? -1 : 1);
                    bool flag_nlz = 0;
                    (j == 1 ? s_cw[n*2] : s_cw[j]).clear();
                    for(int z : s_cw[lz])
                    {
                        if(z > c[i])
                        {
                            (j == 1 ? s_cw[n*2] : s_cw[j]).insert(z);
                            flag_nlz = 1;
                        }
                        else if(a[z] >= l)
                        {
                            (j == 1 ? s_cw[n*2] : s_cw[j]).insert(z);
                        }
                        else
                        {
                            flag_nlz = 1;
                        }
                    }
                    if(flag_nlz)
                    {
                        for(int z : s_cw[lz+dt])
                        {
                            (j == 1 ? s_cw[n*2] : s_cw[j]).insert(z);
                        }
                    }
                    if(j == 1)
                    {
                        s_cw[1] = s_cw[n*2];
                    }
                }
            }
            ll cnt = 0;
            for(int z : s_cw[1])
            {
                cnt += z;
            }
            ans ^= (cnt * i);
            //cout << cnt << " ";
        }
        cout << ans << endl;
    }
    return 0;
}
