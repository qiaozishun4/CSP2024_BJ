#include <iostream>
#include <queue>
#include <map>
using namespace std;

const int maxn = 100005;

int beg[6] = {1, 2, 4, 6, 7, 8};
int st[6] = {0, 1, 2, 4, 7, 8};
int f[6] = {6, 2, 5, 4, 3, 7};
int f1[6] = {2, 5, 4, 6, 3, 7};
bool vis[maxn];
int t, n;

map <int, string> ans;

struct Node{
    int trg;
    string num;
};

void solve(){
    queue <Node> q;
    for (int i = 0; i < 6; i++){
        string s = to_string(beg[i]);
        ans[f1[i]] = s;
        vis[f1[i]] = 1;
        q.push({f1[i], s});
    }
    while (q.size()){
        Node node = q.front(); q.pop();
        int u = node.trg;
        for (int i = 0; i < 6; i++){
            if (u+f[i] > maxn || vis[u+f[i]]) continue;
            string s1 = node.num+to_string(st[i]);
            ans[u+f[i]] = s1;
            vis[u+f[i]] = 1;
            q.push({u+f[i], s1});
        }
    }
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    cin >> t;
    while (t--){
        cin >> n;
        cout << (vis[n] ? ans[n] : "-1") << "\n";
    }
    return 0;
}
