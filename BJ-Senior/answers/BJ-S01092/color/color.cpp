#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdlib>
#define ll long long
#define o1 first
#define o2 second
#define omp make_pair
#define opb push_back
#define inf 3423423423423423422ll
#define MAX_N 522222

using namespace std;

ll read(){ll x = 0;char c = 0;bool v = 0;do{c = getchar();if(c == '-')v = 1;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');return v ? -x : x;}
char gtc(){char c = 0;while(c < 33 && c != EOF)c = getchar();return c;}

template<size_t N>
struct jnode
{
    int n, m;
    pair<ll, int> jv[N];
    int ja[N];
    ll jo[N];
    void push_back(ll x) { n++, jv[n] = omp(x, n); }
    void rebuild()
    {
        m = 0;
        sort(jv + 1, jv + n + 1);
        for(int i = 1; i <= n; i++)
        {
            if(i == 1 || jv[i].o1 != jv[i - 1].o1)
                jo[++m] = jv[i].o1;
            ja[jv[i].o2] = m;
        }
    }

    int operator [] (int x) { return ja[x]; }
    ll operator () (int x) { return jo[ja[x]]; }
    ll decode(int x) { return jo[x]; }

    void clear() { n = m = 0; }
};

struct node
{
    int l, r;
    ll mx, d;
    node *lc, *rc;
    void pUp() { mx = max(lc->mx, rc->mx); }
    void add(ll x) { mx += x, d += x; }
    void pDown()
    {
        if(l != r && d)
            lc->add(d), rc->add(d), d = 0;
    }

    void update(int L, int R, ll x)
    {
        if(L > R)
            return;
        pDown();
        if(l == L && r == R)
        {
            add(x);
            return;
        }
        int mid = (l + r) >> 1;
        if(R <= mid)
            lc->update(L, R, x);
        else if(L > mid)
            rc->update(L, R, x);
        else
            lc->update(L, mid, x), rc->update(mid + 1, R, x);
        pUp();
    }

    ll query(int L, int R)
    {
        if(L > R)
            return -inf;
        pDown();
        if(l == L && r == R)
            return mx;
        int mid = (l + r) >> 1;
        if(R <= mid)
            return lc->query(L, R);
        if(L > mid)
            return rc->query(L, R);
        return max(lc->query(L, mid), rc->query(mid + 1, R));
    }

    void set(int x, ll k)
    {
        pDown();
        if(l == r)
        {
            mx = max(mx, k);
            return;
        }
        int mid = (l + r) >> 1;
        if(x <= mid)
            lc->set(x, k);
        else
            rc->set(x, k);
        pUp();
    }
} _pool[MAX_N << 1], *null = _pool;

int _tot = 0;

node* make(int l, int r)
{
    _pool[++_tot] = (node){l, r, -inf, 0, null, null};
    return _pool + _tot;
}

node* bT(int l, int r)
{
    node* t = make(l, r);
    if(l == r)
        return t;
    int mid = (l + r) >> 1;
    t->lc = bT(l, mid), t->rc = bT(mid + 1, r);
    return t;
}

int n;
jnode<MAX_N> a;

void oM()
{
    n = read();
    for(int i = 1; i <= n; i++)
        a.opb(read());
    a.rebuild();
    node* t = bT(0, a.m);
    t->set(0, 0);
    for(int i = 2; i <= n; i++)
    {
        ll k = max(max(t->query(0, a[i] - 1), t->query(a[i] + 1, a.m)), t->query(a[i], a[i]) + a(i));
        if(a(i) == a(i - 1))
            t->add(a(i));
        t->set(a[i - 1], k);
    }
    printf("%lld\n", t->mx);
}

void oC()
{
    _tot = 0;
    a.clear();
}

void oE()
{
    ;
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    oE();
    int T = read();
    while(T--)
        oM(), oC();
    return 0;
}
