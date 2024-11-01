#include <bits/stdc++.h>
using namespace std;
int t,n,k,q;
int l[100005],h[100005];
vector <int> s[100005];
struct ed {
    int to;
    int w;
    int nxt;
};
vector <ed> e;
int tot;
inline void init () {
    memset(l,0,sizeof(l));
    memset(h,0,sizeof(h));
    for (int i = 1;i <= n;i++) {
        s[i].clear();
    }
    e.clear();
    tot = 0;
    ed E;
    E.to = 0;
    E.nxt = 0;
    E.w = 0;
    e.push_back(E);
    return;
}
inline void add (int u,int v,int w) {
    ed E;
    E.to = v;
    E.nxt = h[u];
    E.w = w;
    tot++;
    h[u] = tot;
    e.push_back(E);
    return;
}
bool dfs (int p,int d,int ee,int r,int c) {
    if (p == 0) {
        return false;
    }
    //cout << p << endl;
    if (d == r) {
        if (p == c) {
            return true;
        } else {
            return false;
        }
    }
    for (int i = h[p];i;i = e[i].nxt) {
        int v = e[i].to,w = e[i].w;
        if (w == ee) {
            continue;
        }
        if (dfs(v,d + 1,w,r,c)) {
            return true;
        }
    }
    return false;
}
int main () {
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> t;
    while (t--) {
        init();
        cin >> n >> k >> q;
        for (int i = 1;i <= n;++i) {
            cin >> l[i];
            for (int j = 1;j <= l[i];++j) {
                int S;
                cin >> S;
                s[i].push_back(S);
            }
            for (int u = 0;u < l[i];++u) {
                for (int v = u + 1;v < l[i];++v) {
                    add(s[i][u],s[i][v],i);
                }
            }
        }
        while (q--) {
            int r,c;
            cin >> r >> c;
            cout << dfs(1,0,0,r,c) << endl;
        }
    }
    return 0;
}