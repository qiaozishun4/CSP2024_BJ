#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, k, oa[N], a[N], c[N], p2[21];
vector<int> d[20];
queue<int> q;

inline void solve(){
    for (int t=1; t<=m; t++){
        while (q.empty()) q.pop();
        for (int i=0; i<=20; i++) if (p2[i] >= c[t]){k = i; break;}
        int rnd = 1, f1, f2, lwin. rwin;
        for (int i=1; i<=p2[k-1]; i++) q.push(i);
        for (int rnd=1; rnd<k; rnd++){
            for (int i=1; i<=p2[k - rnd]; i+=2){
                f1 = q.front(); q.pop();
                f2 = q.front(); q.pop();
                if (d[rnd][(i + 1) / 2] == 0){
                    if (a[f1] >= rnd) q.push(f1);
                    else q.push(f2);
                }
                else{
                    if (a[f2] >= rnd) q.push(f2);
                    else q.push(f1);
                }
            }
        }
        lwin = q.front(); q.pop();
        rwin = q.front(); q.pop();
        if (d[k][1] == 0 && a[lwin] >= k){printf("%d\n", lwin); continue;}
        else if (d[k][1] == 0){printf("%d\n", rwin); continue;}
        else if (d[k][1] == 1 && a[rwin] >= k){printf("%d\n", rwin); continue;}
        else{printf("%d\n", lwin); continue;}
    }
}

int main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m);
    p2[0] = 1;
    for (int i=1; i<=20; i++) p2[i] = p2[i - 1] * 2;
    for (int i=0; i<=20; i++) if (p2[i] >= n){k = i; break;}
    for (int i=1; i<=n; i++) scanf("%d", &oa[i]);
    for (int i=1; i<=m; i++) scanf("%d", &c[i]);
    int t;
    for (int i=1; i<=k; i++){
        for (int j=1; j<=p2[k - i + 1]; j++) scanf("%1d", &t) d[i].push_back(t);
    }
    int T, x[4];
    scanf("%d", &T);
    
    while (T--){
        for (int i=0; i<4; i++) scanf("%d", &x[i]);
        for (int i=1; i<=n; i++) a[i] = oa[i] ^ x[i % 4];
        solve();
    }
    return 0;
}
