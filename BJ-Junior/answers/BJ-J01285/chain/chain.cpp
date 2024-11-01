#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a[100005];
vector<pair<int, int>> use[200005];
bool dfs(int x, int y, int from){
    if(x == 0 && y == 1){
        return 1;
    }else if(x == 0){
        return 0;
    }
    for(int i = 0; i < use[y].size(); i++){
        if(use[y][i].first == from){
            continue;
        }
        for(int k = max(use[y][i].second - m + 1, 0); k < use[y][i].second; k++){
            if(dfs(x - 1, a[use[y][i].first][k], i) == 1){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
            a[i].clear();
            int len;
            cin >> len;
            for(int j = 1; j <= len; j++){
                int x;
                cin >> x;
                a[i].emplace_back(x);
                use[x].push_back({i, j});
            }
        }
        while(k--){
            int x, y;
            cin >> x >> y;
            cout << dfs(x, y, 0) << '\n';
        }
    }
    return 0;
}
