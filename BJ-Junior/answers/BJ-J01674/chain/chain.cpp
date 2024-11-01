#include<bits/stdc++.h>
using namespace std;
struct node{
    int id,v;
};
struct node_{
    int now,k,d,id;
};
bool vis[105][200005];
vector <node> s[200005];
queue <node_> q;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n,m,tq;
        cin >> n >> m >> tq;
        m--;
        for(int i = 1;i <= 2e5;i++) s[i].clear();
        for(int i = 1;i <= n;i++){
            int l,u,v;
            cin >> l >> u;
            for(int j = 1;j < l;j++){
                cin >> v;
                s[u].push_back({i,v});
                u = v;
            }
            for(int j = 1;j <= 100;j++){
                vis[j][i] = 0;
            }
        }
        q.push({1,m,0,0});
        while(q.size()){
            node_ now = q.front();
            q.pop();
            //cout << now.now << " " << now.k << " " << now.d << " " << now.id << endl;
            if(now.k < 0) continue;
            if(m - now.k >= 1) vis[now.d + 1][now.now] = 1;
            if(now.d == 10) continue;
            for(int i = 0;i < s[now.now].size();i++){
                node x = s[now.now][i];
                if(x.id == now.id || (now.id + x.id && now.id < 0) || !now.id){
                    q.push({x.v,now.k - 1,now.d,x.id});
                }
            }
            if(m - now.k >= 1) q.push({now.now,m,now.d + 1,-now.id});
        }
        /*for(int i = 1;i <= 6;i++){
            for(int j = 1;j <= 5;j++) cout << vis[j][i] << " ";
            cout << endl;
        }*/
        while(tq--){
            int u,v;
            cin >> u >> v;
            if(vis[u][v]) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}
