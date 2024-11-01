#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

const int N = 1e5;
const int K = 20;

int n, m, t;
long long ans;
int aa[N], x[N], a[N], c[N];
bool d[K][N];

int gerl(int &, int, int);
int getr(int &, int, int);
int calc(int, int);

int main(void)
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> aa[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; (1 << (i + 1)) < n * 2; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            d[i][j] = s[j] - '0';
        }
    }

    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++)
        {
            a[i] = aa[i] ^ x[(i + 1) % 4];
            //cout<<a[i]<<' ';
        }
        //cout<<endl;

        ans = 0;
        for (int i = 0; i < m; i++)
        {
            //cout<<c[i]<<' '<<((1 << (int)ceil(log2(c[i]))) - 1)<<endl;
            ans ^= 1LL * (i + 1) * (calc(0, ((1 << (int)ceil(log2(c[i]))) - 1)) + 1);
        }
        cout << ans << endl;
    }

    return 0;
}

int getl(int &ll, int l, int r)
{
    if (ll == -1)
    {
        if (l == r - 1)
        {
            ll = l;
        }
        else
        {
            ll = calc(l, (l + r) / 2);
        }
    }
    return ll;
}

int getr(int &rr, int l, int r)
{
    if (rr == -1)
    {
        if (l == r - 1)
        {
            rr = r;
        }
        else
        {
            rr = calc((l + r) / 2 + 1, r);
        }
    }
    return rr;
}

int calc(int l, int r)
{
    int ll = -1, rr = -1, lg = log2(r - l + 1);
    //cout<<l<<' '<<r<<" "<<lg-1<<' '<<l / (1 << lg)<<' '<<d[lg - 1][l / (1 << lg)]<<endl;
    if (d[lg - 1][l / (1 << lg)])
    {
        if (a[getr(rr, l, r)] >= lg)
        {
            return getr(rr, l, r);
        }
        return getl(ll, l, r);
    }
    if (a[getl(ll, l, r)] >= lg)
    {
        return getl(ll, l, r);
    }
    return getr(rr, l, r);
}