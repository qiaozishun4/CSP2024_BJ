#include<bits/stdc++.h>
using namespace std;
const int NR = 1e5;
const int MR = 2e5;
vector<int> a[NR + 10];
vector<pair<int, int> > mp[NR + MR + 10];
struct Node{
    int u, last, dis, len;
};
queue<Node> q;
// map<pair<int, int>, bool> vis;
int n, Max;
bool bfs(int st, int ed, int r, int k){
    while(!q.empty()) q.pop();
    // vis.clear();
    q.emplace(Node{st, -1, 0, 0});
    // vis[make_pair(st, 0)] = true;
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        // printf("u=%d last=%d dis=%d len=%d\n", top.u, top.last, top.dis, top.len);
        if(top.dis == r){
            if(top.u == ed){
                return true;
            }
            continue;
        }
        int u = top.u;
        for(auto i : mp[u]){
            int v = i.first;
            int w = i.second;
            // printf("  v=%d w=%d\n", v, w);
            if(v == top.last) continue;
            // if(vis[make_pair(v, top.dis + 1)]) continue;
            if(v > Max){
                q.emplace(Node{v, v, top.dis, w});
            }
            else{
                if(top.len + w > 0 && top.len + w < k){
                    q.emplace(Node{v, top.last, top.dis + 1, 0});
                }
            }
        }
    }
    return false;
}

int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        int k, q;
        scanf("%d%d%d", &n, &k, &q);
        Max = 0;
        for(int i = 1;i <= n;i++){
            int l, x;
            scanf("%d", &l);
            for(int j = 1;j <= l;j++){
                scanf("%d", &x);
                a[i].emplace_back(x);
                Max = max(Max, x);
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < a[i].size();j++){
                mp[Max + i].emplace_back(make_pair(a[i][j], j + 1));
                mp[a[i][j]].emplace_back(make_pair(Max + i, -j - 1));
            }
        }
        for(int i = 1;i <= Max + n;i++){
            for(auto j : mp[i]){
                // printf("%d--(%d)-->%d\n", i, j.second, j.first);
            }
        }
        while(q--){
            int r, ed;
            scanf("%d%d", &r, &ed);
            if(ed > Max){
                printf("0\n");
                continue;
            }
            bool flag = bfs(1, ed, r, k);
            printf("%d\n", flag ? 1 : 0);
        }
        for(int i = 1;i <= Max + n;i++){
            mp[i].clear();
        }
        for(int i = 1;i <= n;i++){
            a[i].clear();
        }
    }
    return 0;
}
/*
cd ~/GJH/chain && g++ chain.cpp && ./a.out

1
3 3 7
5 1 2 3 4 1
3 1 2 5
3 5 1 6
1 2
1 4
2 4
3 4
6 6
1 1
7 7

*/