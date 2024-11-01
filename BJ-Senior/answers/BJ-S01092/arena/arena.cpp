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
#define MAX_N 222222

using namespace std;

ll read(){ll x = 0;char c = 0;bool v = 0;do{c = getchar();if(c == '-')v = 1;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');return v ? -x : x;}
char gtc(){char c = 0;while(c < 33 && c != EOF)c = getchar();return c;}

int log_2[MAX_N << 1];
int n, m, k;
ll na[MAX_N << 1], a[MAX_N << 1];
int cp[MAX_N << 1];
bool l[MAX_N << 1];
ll X0, X1, X2, X3;
int H, L, key;
ll val[MAX_N << 1];
bool chs[MAX_N << 1]/*dir of line*/;
ll s[MAX_N << 1]/*sum of id*/, t[MAX_N << 1]/*level*/;
ll ans[MAX_N << 1];

inline int level(int x) { return k - log_2[x]; }

bool ol[MAX_N]/*if on line*/
bool tps[MAX_N];
ll sr[MAX_N], tr[MAX_N];

ll check(int rt, int dn)
{
    int u = level(rt), d = level(dn);
    int tot = u;
    for(int i = rt; i <= dn; i = i * 2 + chs[i])
    {
        ol[tot] = (chs[i] == l[i]), tps[tot] = chs[i];
        if(i != dn)
            sr[tot] = s[i * 2 + !chs[i]], tr[tot] = t[i * 2 + !chs[i]];
    }
    for(int i = d + 1; i <= u; i++)

}

void renew(int x)
{
    if(x & 1)
    {
        int id = x, tid = x;
        for(int i = (x >> 1); ; i >>= 1)
        {
            id = i;
            if((!l[i] && t[i << 1] >= level(i)) || (l[i] && t[(i << 1) | 1] < level(i)))
                tid = s[i << 1];
            if(i == 1 || !(i & 1))
                break;
        }
        s[id] = tid, t[id] = a[tid];
    }
}

void oM()
{
    X0 = read();
    X1 = read();
    X2 = read();
    X3 = read();
    for(int i = (1 << k) + 3; i < (1 << k) + n; i++)
        a[i] = (na[i] ^ X0);
    for(int i = (1 << k); i < (1 << k) + n; i++)
        a[i] = (na[i] ^ X1);
    for(int i = (1 << k) + 1; i < (1 << k) + n; i++)
        a[i] = (na[i] ^ X2);
    for(int i = (1 << k) + 2; i < (1 << k) + n; i++)
        a[i] = (na[i] ^ X3);
}

void oC()
{
    ;
}

void oE()
{
    log_2[0] = -1;
    for(int i = 1; i < (MAX_N << 1); i++)
        log_2[i] = log_2[i >> 1] + 1;
    n = read();
    m = read();
    for(int i = 20; ~i; i--)
        if((1 << i) >= n)
            k = i;
    for(int i = (1 << k); i < (1 << k) + n; i++)
        na[i] = read();
    for(int i = 1; i <= m; i++)
        cp[i] = read();
    for(int j = k - 1; ~j; j--)
        for(int i = (1 << j); i < (1 << (j + 1)); i++)
            l[i] = (gtc() == '1');
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    oE();
    int T = read();
    while(T--)
        oM(), oC();
    return 0;
}
