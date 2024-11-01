#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5, M = 1e6+5;
int T, n, m, l, v, ans, mn, sz, st, s[M], t[M], p[N], mk[N], dp[M];
struct node{
    int d, v, a, l, r, f;
} c[N];
struct npd{
    int l, r;
    bool operator >(const npd &b) const{
        if(l != b.l) return l < b.l;
        return r < b.r;
    }
} x[N];
bool cmp(npd x, npd y){
    if(x.r != y.r) return x.r < y.r;
    return x.l < y.l;
}
//bool check(){
//    bool flag[25];
//    memset(flag, 0, sizeof(flag));
//    for(int i = 1; i <= m; i++)
//        if(mk[i])
//            for(int j = 1; j <= n; j++)
//                if()
//}
//void dfs(int x, int cnt){
//    if(x > m){
//        if(check()) mn = min(mn, cnt);
//        return;
//    }
//    mk[x] = 0, dfs(x+1, cnt);
//    mk[x] = 1, dfs(x+1, cnt+1);
//}
void print(priority_queue<npd, vector<npd>, greater<npd> > q){
    while(!q.empty()){
        cout<<q.top().l<<" "<<q.top().r<<endl;
        q.pop();
    }
    cout<<endl;
}
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>T;
    while(T--){
        memset(s, 0, sizeof(s));
        memset(t, 0, sizeof(t));
        memset(dp, 0, sizeof(dp));
        mn = 1e9, ans = 0, sz = 0, st = 0;
        cin>>n>>m>>l>>v;
        bool f1 = 0, f2 = 0, f3 = 0;
        for(int i = 1; i <= n; i++) c[i].f = 0, c[i].l = c[i].r = -1;
        for(int i = 1; i <= n; i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].a != 0) f1 = 1;
            if(c[i].a > 0) f2 = 1;
            if(c[i].a < 0) f3 = 1;
            if(c[i].a <= 0 && c[i].v <= v) continue;
            if(c[i].a == 0) c[i].l = c[i].d, c[i].r = l;
            else{
                double t = 1.0 * fabs((v - c[i].v)) / fabs(c[i].a) * 1.0;
                if(c[i].a > 0){
                    if(c[i].v > v) c[i].l = c[i].d, c[i].r = l;
                    else{
                        double len = t * (1.0 * v + c[i].v) / 2.0 + c[i].d;
                        if(int(len) + 1 <= l) c[i].l = int(len) + 1, c[i].r = l;
                    }
                }
                else{
                    double len = t * (1.0 * v + c[i].v) / 2.0 + c[i].d;
                    c[i].l = c[i].d, c[i].r = min(int(len), l);
                }
            }
        }
        for(int i = 1; i <= m; i++){
            cin>>p[i];
            t[p[i]] = 1;
        }
        for(int i = 1; i <= l; i++) t[i] += t[i-1];
        for(int i = 1; i <= n; i++){
            int num;
            if(c[i].l == 0) num = 0;
            else num = t[c[i].l-1];
            if(c[i].l >= 0 && c[i].r >= 0 && t[c[i].r] - num > 0) c[i].f = 1, ans++, x[++sz] = {c[i].l, c[i].r}, st = max(st, c[i].l);
        }
        cout<<ans<<" ";
        //if(n <= 20 && m <= 20){
        //    dfs(1, 0);
        //    cout<<mn<<"\n";
        //}
        if(f1 == 0 || f3 == 0){
            if(ans == 0) cout<<m<<"\n";
            else cout<<m-1<<"\n";
            continue;
        }
        //if(n <= 3000 && m <= 3000){
        //for(int i = 1; i <= n; i++) cout<<p[i]<<" ";
        //cout<<"\n";
        sort(x+1, x+1+sz, cmp);
        //for(int i = 1; i <= sz; i++) cout<<x[i].l<<" "<<x[i].r<<endl;
        //for(int i = 1; i <= sz; i++) cout<<x[i].l<<" "<<x[i].r<<endl;
        int j = 1, k = 1;
        priority_queue<npd, vector<npd>, greater<npd> > q;
        for(int i = 1; i <= m; i++){
            while(j <= sz && x[j].r < p[i]) q.push((npd){x[j].l, x[j].r}), j++;
            //cout<<i<<endl;
            //print(q);
            while(k < i && !q.empty() && p[k] < q.top().l) k++;
            if(!q.empty() && k < i){
                int tmp = 1e9;
                for(int ll = k; ll < i; ll++) tmp = min(tmp, dp[ll]);
                //if(i == 4 && k == 2) cout<<tmp<<endl;
                dp[i] = tmp + 1;
            }
            else dp[i] = 1;
            //cout<<dp[i]<<" "<<k<<endl;
        }
        st = lower_bound(p+1, p+1+m, st) - p;
        for(int i = st; i <= m; i++) mn = min(mn, dp[i]);
        cout<<m - mn<<"\n";
        //}
    }
    return 0;
}
