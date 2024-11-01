

#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const double eps = 1e-8;
const int mxn = 1e5 + 10, mxl = 1e6 + 10;
int n, m, CAS = 0, L, V, test, cnt, ans1, ans2, p[mxn], pre[mxl], suf[mxl];

bool is[mxl], vis[mxn];
struct node{
    int d, v, a;
}s[mxn];

struct query{
    int op, id;
};

struct seg{
    int l, r, id;
}t[mxn];
vector<query> vec[mxn];
vector<int> que;

inline void init(){
    n = m = L = V = cnt = ans1 = ans2 = test = 0;
    memset(p, 0, sizeof(p));
    memset(pre, 0, sizeof(pre));
    memset(suf, 0, sizeof(suf));
    memset(is, 0, sizeof(is));
    memset(vis, 0, sizeof(vis));
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));
}
bool cmp(query x, query y){
    return x.op > y.op;
}

inline void insert(int L, int R, int x){
  //if(CAS == 9)  cerr << L << ' ' << R << ' ' << m << ' ' << s[x].v << ' ' << V << ' ' << x << endl;
    if(!L || !R || L > R || L > m || R > m){
     //   cerr << L << ' ' << R << ' ' << s[x].d << endl;
        return;
    }
   //if(CAS == 9) cerr << x << endl;
    t[++cnt] = (seg){L, R, x};
}

inline void find(int x){
    if(s[x].a == 0){
        if(s[x].v > V){
            test++;
            insert(suf[s[x].d], pre[L], x);
        }
    }
    else if(s[x].a > 0){
        if(s[x].v > V) insert(suf[s[x].d], pre[L], x);
        else{
            int X = (V * V - s[x].v * s[x].v) / (2 * s[x].a);
            int pos = s[x].d + X + 1;
            if(pos <= L) insert(suf[pos], pre[L], x);
        }
    }
    else{
        if(s[x].v <= V) return;
        int X = (V * V - s[x].v * s[x].v) / (2 * s[x].a), Y = (V * V - s[x].v * s[x].v) % (2 * s[x].a);
        int pos = s[x].d + X;
        if(!Y) pos--;
       // if(x == 4) cout << pos << ' ' << pre[pos] << endl;
        if(pos <= L) insert(suf[s[x].d], pre[pos], x);
        else insert(suf[s[x].d], pre[L], x);
    }
}

inline void solve(){
    cin >> n >> m >> L >> V;
  //  cerr << n << endl;
    for(int i = 1; i <= n; i++) cin >> s[i].d >> s[i].v >> s[i].a;
    for(int i = 1; i <= m; i++){
        cin >> p[i];
    }
    sort(p + 1, p + m + 1);
    int ls = 0;
    for(int i = 0; i <= L; i++){
        if(ls < m && p[ls + 1] <= i){
           // cerr << p[ls + 1] << ' ' << i << endl;
            ls++;
        }
        pre[i] = ls;
    }
    ls = m + 1;
    for(int i = L; i >= 0; i--){
        if(ls > 1 && p[ls - 1] >= i) ls--;
        suf[i] = ls;
    }
    for(int i = 1; i <= n; i++) find(i);
   // cerr << test << endl;
    ans1 = cnt;
    for(int i = 1; i <= cnt; i++){
        vec[t[i].l].push_back({1, t[i].id});
        vec[t[i].r].push_back({-1, t[i].id});
    }
   // cerr << "reoiurewoiuoirew" << endl;
    int res = 0;
    for(int i = 1; i <= m; i++){
        if(!vec[i].size()) continue;
        sort(vec[i].begin(), vec[i].end(), cmp);
        
        bool jud = false;
        for(auto it : vec[i]){
            if(it.op > 0) que.push_back(it.id);
            else if(!vis[it.id]) jud = true;
        }//cerr << i << endl;
        if(jud){
            res++;
            //cerr << que.size() << endl;
            for(auto it : que){
               // cerr << it << endl;
                vis[it] = true;
            }
           // cerr << "4333" << endl;
            que.clear();
        }
    }
    que.clear();
    // cerr << "reoiurewoiuoirew" << endl;
    for(int i = 1; i <= m; i++) vec[i].clear();
    ans2 = res;
    cout << ans1 << ' ' << m - ans2 << '\n';
}

signed main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T = 1;
    cin >> T;
    while(T--){
        CAS++;
        init();
        solve();
    }
    return 0;
}