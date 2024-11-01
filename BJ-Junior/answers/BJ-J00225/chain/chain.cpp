#include<iostream>

using namespace std;

int l[2005], a[2005][2005];
bool f[2005], vis[2005][2005];
int r[2005], c[2005];

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
        for(int i = 1; i <= n; i++)
        {
            cin >> l[i];
            for(int j = 1; j <= l[i]; j++)
            {
                cin >> a[i][j];
                if(a[i][j] == 1) f[i] = true;
            }
        }
        for(int i = 1; i <= q; i++)
        {
            cin >> r[i] >> c[i];
        }
        for(int k = 1; k <= q; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= l[i]; j++)
                    if(a[i][j] == c[k]) vis[i][k] = true;
        for(int k = 1; k <= q; k++)
        {
            bool ans = 0;
            for(int i = 1; i <= n; i++)
                if(f[i] == 1 && vis[i][k] == 1) ans = 1;
            cout << ans << endl;
        }
    }
    return 0;
}
