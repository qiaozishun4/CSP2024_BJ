#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct node {
    int p, s, step;
};

struct query {
    int r, c, id;
    bool operator <(const query &b){
        return r < b.r;
    }
} qs[MAXN];

int T, n, k, Q, r, c, ans[MAXN];
vector<int> a[MAXN];
map<int, set<int>> e[MAXN];

void check(){
    queue<node> q; int z = 1;
    while (!q.empty()) q.pop();
    q.push({1, 0, 0});
    while (!q.empty()){
        node u = q.front(); q.pop();
        while (u.step > qs[z].r && z <= Q) z++;
        if (z == Q + 1) return ;
        if (u.step == qs[z].r){
            for (int i = z; qs[z].r == qs[i].r; i++){
                if (u.p == qs[i].c) {
                    ans[qs[i].id] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++){
            if (i == u.s) continue;
            if (!e[i].count(u.p)) continue;
            for (int v : e[i][u.p]){
                q.push({v, i, u.step+1});
            }
        }
    }
    return ;
}

int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while (T--){
        cin >> n >> k >> Q;
        for (int i = 1; i <= n; i++){
            e[i].clear();
            int m; cin >> m;
            for (int j = 1; j <= m; j++){
                int x; cin >> x;
                a[i].push_back(x);
            }
            for (int j = 0; j < m; j++){
                for (int h = 1; h < k; h++){
                    if (j + h >= m) break;
                    e[i][a[i][j]].insert(a[i][j+h]);
                }
            }
            a[i].clear();
        }
        for (int i = 1; i <= Q; i++){
            cin >> qs[i].r >> qs[i].c; qs[i].id = i;
            ans[i] = 0;
        }
        sort(qs+1, qs+Q+1);
        check();
        for (int i = 1; i <= Q; i++){
            cout << ans[i] << endl;
        }
    }
    return 0;
}
