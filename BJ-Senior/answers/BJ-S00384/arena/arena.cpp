#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int n, m, K;
string q[35];
int a[150005], c[150005];
int b[150005];
int bs;
ll s[300005][21];
void pushup(int rt, int f, int d)
{
    int son = rt<<1|f;
    bool fl = 0;
    if(s[son][20]) fl = 1;
    else for(int i = 0; i < d; i++) if(s[son][i]) { fl = 1; break; }
    if(fl) memcpy(s[rt], s[son^1], sizeof(s[0]));
    else memset(s[rt], 0, sizeof(s[0]));
    for(int i = d; i <= 20; i++) s[rt][i] += s[son][i];
}
void build(int rt, int l, int r, int d)
{
    if(l == r)
    {
        if(l < (1<<(bs-1))) s[rt][min(a[l], 19)] = l+1;
        else s[rt][20] = l+1;
        return;
    }
    int mid = (l+r)>>1;
    build(rt<<1, l, mid, d-1);
    build(rt<<1|1, mid+1, r, d-1);
    char f = q[d][rt^(1<<(31^__builtin_clz(rt)))];
    pushup(rt, f, d);
}
void upd(int rt, int l, int r, int k, int c, int d)
{
    s[rt][20] -= k+1;
    if(l == r)
    {
        s[rt][c] = k+1;
        return;
    }
    int mid = (l+r)>>1;
    if(k <= mid) upd(rt<<1, l, mid, k, c, d-1);
    else upd(rt<<1|1, mid+1, r, k, c, d-1);
    char f = q[d][rt^(1<<(31^__builtin_clz(rt)))];
    pushup(rt, f, d);
}
ll sum(ll *a)
{
    ll ans = 0;
    for(int i = 0; i <= 20; i++) ans += a[i];
    return ans;
}
// void dbg(int rt, int l, int r)
// {
//     cerr << rt << ": ";
//     for(int i = 0; i <= 20; i++) cerr << s[rt][i] << " " ;
//     cerr << endl;
//     if(l == r) return;
//     int mid = (l+r)>>1;
//     dbg(rt<<1, l, mid);
//     dbg(rt<<1|1, mid+1, r);
// }
ll ans[150005];
void solve()
{
    ans[0] = 1;
    for(bs = 1; bs <= K; bs++)
    {
        for(int i = 0; i <= (1<<(bs+1)); i++)
        {
            for(int j = 0; j <= 20; j++) s[i][j] = 0;
        }
        build(1, 0, (1<<bs)-1, bs);
        for(int i = (1<<(bs-1)); i < n && i < (1<<bs); i++)
        {
            upd(1, 0, (1<<bs)-1, i, min(a[i], 19), bs);
            if((i>>(bs-1))&1)
            {
                ans[i] = sum(s[1]);
            }
        }
    }
    ll ret = 0;
    for(int i = 1; i <= m; i++)
    {
        ret ^= ans[c[i]-1]*i;
    }
    cout << ret << endl;
}
int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 1; i <= m; i++) cin >> c[i];
    while((1<<K) < n) K++;
    for(int i = 1; i <= K; i++)
    {
        cin >> q[i];
        for(auto &c: q[i]) c -= '0';
    }
    int T;
    cin >> T;
    while(T--)
    {
        int X[4];
        for(int i = 0; i <= 3; i++) cin >> X[i];
        for(int i = 0; i < n; i++) a[i] = b[i]^X[(i+1)&3];
        solve();
    }
    return 0;
}