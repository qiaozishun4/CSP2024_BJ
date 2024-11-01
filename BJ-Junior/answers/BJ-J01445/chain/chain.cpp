#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, k, q;
vector <int> a[N];

map <int, bool> z[110];
void dfs(int p, int v, int s){
    if (s > 100) return;
    z[s][v] = 1;
    for (int i = 1; i <= n; i ++){
        if (i == p) continue;
        for (int j = 0; j < a[i].size(); j ++){
            if (a[i][j] != v) continue;
            for (int l = 1; l < k; l ++)
                if (j + l < a[i].size()) dfs(i, a[i][j + l], s + 1);
        }
    }
}

int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    while (t --){
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i ++){
            int len;
            cin >> len;
            for (int j = 1; j <= len; j ++){
                int x;
                cin >> x;
                a[i].push_back(x);
            }
            dfs(1, 1, 0);
            dfs(2, 1, 0);
            dfs(3, 1, 0);
            while (q --){
                int r, c;
                cin >> r >> c;
                if (z[r].count(c)) cout << 1 << endl;
                else cout << 0 << endl;
            }
        }
    }
    return 0;
}