#include <bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int a[20010][20010], b[20010];
int r[100010], c[100010], ans[100010];
struct node{
    int x, i;
};
bool dfs(int n, int k){
    queue<node> q;
    for (int i = 1; i <= 20000; i++){
        if (b[i]) q.push(node{i, 1});
    }
    while (!q.empty()){
        node u = q.front();
        q.pop();
        if (u.i > n) break;
        for (int i = 1; i <= k; i++) if (u.x == c[i] && u.i == r[i]) ans[i] = 1;
        for (int i = 1; i <= 20000; i++){
            if (a[u.x][i]) q.push(node{i, u.i+1});
        }
    }
}
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T, n, k, q, l, x;
    cin >> T;
    while (T--){
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++){
            cin >> l;
            for (int j = 1; j <= l; j++){
                cin >> x;
                v[i].push_back(x);
            }
            for (int j = 0; j < l; j++){
                for (int m = j+1; m < l; m++){
                    if (m-j+1 > k) break;
                    a[v[i][l]][v[i][m]] = 1;
                    b[v[i][l]] = 1;
                }
            }
        }
        x = 0;
        for (int i = 1; i <= q; i++){
            cin >> r[i] >> c[i];
            x = max(x, r[i]);
        }
        dfs(x, q);
        for (int i = 1; i <= q; i++) cout << ans[i] << endl;
    }
    return 0;
}
