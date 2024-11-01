#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MAXN = 200010;
const int INF  = 0x3f3f3f3f;
const ll INFL  = 0x3f3f3f3f3f3f3f3f;
const double MMIN = 1e-6;
#define i128 __int128
#define pii pair<int, int>
#define mkp(A, B) make_pair(A, B)
#define F first
#define S second

int T, n, m, L, V;
struct Cars {
    int di, vi, ai;
} ci[MAXN];
int pi[MAXN], hv[MAXN * 10];
const pii NoneOver = mkp(INF, INF);
pii Calc(int di, int a, int v0)
{
    pii Ret = mkp(INF, INF);
    if(a == 0) {
        if(v0 > V) return mkp(di, L);
        else return Ret;
    }
    ld des = (V * V - v0 * v0) / (2.0 * a);
    // cout << des << " ";
    if(des < 0 && a < 0) return Ret;
    else if(di + des > L && a > 0) return Ret;
    if(a < 0) 
        return mkp(di, min(L, (int)(di + des)));
    else 
        return mkp(max(di, (int)(di + des + 1.1)), L);
    return Ret;
}
int reCalc(int nb, int des, bool oc)
{
    for(int i = max(des - 5, ci[nb].di); i <= min(L, des + 5); i++) {
        int nw = i - ci[nb].di;
        int v2 = ci[nb].vi * ci[nb].vi + 2 * ci[nb].ai * nw;
        if(oc == 0) {
            if(v2 > V * V) return i;
        } 
        else {
            if(v2 <= V * V) return i - 1;
        }
    }
    return 0;
}


vector< pii > qi;

void init()
{
    memset(hv, 0, sizeof hv);
    qi.clear();
}

void work()
{
    init();
    cin >> n >> m >> L >> V;
    L += 1;
    for(int i = 1; i <= n; i++) {
        cin >> ci[i].di >> ci[i].vi >> ci[i].ai;
        ci[i].di += 1;
    }
    for(int i = 1; i <= m; i++) {
        cin >> pi[i];
        pi[i] += 1;
        hv[pi[i]] = 1;
    }
    for(int i = 1; i <= L + 15; i++) hv[i] += hv[i - 1];
    for(int i = 1; i <= n; i++) {
        pii pn = Calc(ci[i].di, ci[i].ai, ci[i].vi);
        int x = pn.F == ci[i].di ? ci[i].di : reCalc(i, pn.F, 0);
        int y = pn.S == L ? L : reCalc(i, pn.S, 1);
        // cout << pn.F << " " << pn.S << "\n";
        if(pn != NoneOver && hv[y] != hv[x - 1]) {
            
            qi.push_back(mkp(hv[x - 1] + 1, hv[y]));
            // cout << qi.back().F << " " << qi.back().S << "\n";
        }
        // else cout << "False \n";
    }
    sort(qi.begin(), qi.end(), [](pii A, pii B){
        return A.S == B.S ? A.F < B.F : A.S < B.S;
    });
    int ans = (qi.size() ? 1 : 0);
    for(int i = 0, j = qi[0].S; i < qi.size(); i++) {
        while(qi[i].F <= j && i < qi.size()) i++;
        if(i >= qi.size()) break;
        j = qi[i].S, ans++;
    }
    cout << qi.size() << " " << m - ans << "\n";
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        work();
    }
    return 0;
}
// 1 2 3 1 2 -> 1 1 2 2 3