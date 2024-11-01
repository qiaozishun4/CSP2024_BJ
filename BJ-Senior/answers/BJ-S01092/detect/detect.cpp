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

struct qnum
{
    ll a, b; // a / b
    qnum() { a = 0, b = 1; }
    qnum(ll _a, ll _b) : a(_a), b(_b) { ; }
    void stand()
    {
        if(b < 0)
            a = -a, b = -b;
    }

    ll floor()
    {
        stand();
        if(a >= 0)
            return a / b;
        return -((-a + b - 1) / b);
    }

    ll ceil()
    {
        stand();
        if(a >= 0)
            return (a + b - 1) / b;
        return -((-a) / b);
    }
};

bool operator < (qnum a, qnum b)
{
    a.stand(), b.stand();
    return a.a * b.b < b.a * a.b;
}

qnum operator + (qnum a, qnum b) { return qnum(a.a * b.b + b.a * a.b, a.b * b.b); }
qnum operator * (qnum a, qnum b) { return qnum(a.a * b.a, a.b * b.b); }
qnum operator * (qnum a, ll b) { return qnum(a.a * b, a.b); }

int n, m;
ll L, V;

pair<ll, ll> trans(ll p, ll v0, ll a)
{
    //printf("%lld\n", a);
    if(!a)
    {
        if(v0 > V)
            return omp(p, L);
        return omp(0, -1);
    }
    qnum t = qnum(V - v0, a);
    qnum x = t * (qnum(v0, 1) + qnum(1, 2) * t * a);
    if(a > 0)
    {
        if(t < qnum())
            return omp(p, L);
        ll vl = p + x.floor() + 1;
        if(vl > L)
            return omp(0, -1);
        return omp(vl, L);
    }
    //printf("%lld %lld\n", t.a, t.b);
    if(t < qnum())
        return omp(0, -1);
    //printf("%lld\n", p + x.ceil() - 1);
    return omp(p, min(p + x.ceil() - 1, L));
}

pair<ll, ll> a[MAX_N];
ll b[MAX_N];
pair<ll, int> c[MAX_N * 3];
pair<int, int> d[MAX_N];
vector<int> ipr[MAX_N], opr[MAX_N];
bool vis[MAX_N];
vector<int> vec;

void oM()
{
    n = read();
    m = read();
    L = read();
    V = read();
    for(int i = 1; i <= n; i++)
    {
        ll p = read();
        ll v0 = read();
        ll a0 = read();
        a[i] = trans(p, v0, a0);
        //printf("%lld %lld\n", a[i].o1, a[i].o2);
    }
    for(int i = 1; i <= m; i++)
        b[i] = read();
    sort(b + 1, b + m + 1);
    int tot = 0;
    for(int i = 1; i <= n; i++)
        if(a[i].o1 <= a[i].o2)
            c[++tot] = omp(a[i].o1, -i), c[++tot] = omp(a[i].o2, i);
    for(int i = 1; i <= m; i++)
        c[++tot] = omp(b[i], 0);
    sort(c + 1, c + tot + 1);
    for(int i = 1; i <= n; i++)
        d[i] = omp(0, -1);
    int cnt = 0;
    for(int i = 1; i <= tot; i++)
    {
        if(!c[i].o2)
        {
            cnt++;
            continue;
        }
        if(c[i].o2 < 0)
            d[-c[i].o2].o1 = cnt + 1;
        else
            d[c[i].o2].o2 = cnt;
    }
    /*for(int i = 1; i <= n; i++)
        printf("%d %d\n", d[i].o1, d[i].o2);*/
    cnt = 0;
    for(int i = 1; i <= n; i++)
        if(d[i].o1 <= d[i].o2)
            cnt++, ipr[d[i].o1].opb(i), opr[d[i].o2].opb(i);
    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        for(auto j: ipr[i])
            vec.opb(j);
        bool flag = 0;
        for(auto j: opr[i])
            if(!vis[j])
                flag = 1;
        if(flag)
        {
            ans++;
            for(auto j: vec)
                vis[j] = 1;
            vec.clear();
        }
    }
    printf("%d %d\n", cnt, m - ans);
}

void oC()
{
    for(int i = 0; i <= max(n, m) + 5; i++)
        a[i] = d[i] = omp(0, 0), b[i] = vis[i] = 0, ipr[i].clear(), opr[i].clear();
    vec.clear();
}

void oE()
{
    /*ll a = read();
    ll b = read();
    ll c = read();
    printf("%lld %lld %lld\n", a, b, c);*/;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    oE();
    int T = read();
    while(T--)
        oM(), oC();
    return 0;
}
