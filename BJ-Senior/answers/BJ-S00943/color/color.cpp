#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int t, n;
int g[N], ans, res = -1;

vector<int> r, b;

void dfs(int u){
    if(u > n){
        ans = 0;
        int k ,l;
        k = l = -1;
        for(auto x : r){
           // cout << k << ' '<< r[x];
            if(r[x] == k) ans += r[x];
            k = r[x];
        }
        for(auto x : b){
           // cout << l << ' '<< b[x];
            if(b[x] == l) ans += b[x];
            l = b[x];
        }
      
        res = max(res, ans);
        return;
    }

 //   cout << u <<' ' << g[u] <<'\n';
    r.push_back(g[u]);
    dfs(u + 1);
    r.pop_back();

    b.push_back(g[u]);
    dfs(u + 1);
    b.pop_back();
}

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    cin >> t;

    while (t --){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &g[i]);
            cout << g[i] << '\n';
        }
        res = -1;
        dfs(1);
        cout << res << ' ' << "@" << '\n';
    }

    return 0;
}
