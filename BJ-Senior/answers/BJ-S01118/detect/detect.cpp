#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int t, n, m, L, V, d[maxn], v[maxn], a[maxn], p[maxn], ans1, ans2;
vector<int> c[maxn];
bool b[maxn * 10];
set<int> st;
void dfs(int step, vector<int> v) {
    if(step == n) {
        set<int> st;
        for(int x : v) st.insert(x);
        ans2 = max(ans2, n-(int)st.size());
        return;
    }
    if(c[step].empty()) {
        dfs(step + 1, v);
        return;
    }
    for(int x : c[step]) {
        vector<int> t = v;
        t.push_back(x);
        dfs(step + 1, t);
    }
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
        for(int i = 1; i <= m; i++) cin >> p[i], b[p[i]] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = d[i]; j <= L; j++) {
                double ns = sqrt(v[i] * v[i] + 2 * a[i] * (j-d[i]));
                if(ns > V && b[j]) c[i].push_back(j);
            }
        }
        ans1 = 0;
        for(int i = 1; i <= n; i++) if(!c[i].empty()) ans1++;
        ans2 = 0;
        vector<int> e;
        dfs(1, e);
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}