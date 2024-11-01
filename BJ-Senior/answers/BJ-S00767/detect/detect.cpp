#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 9;
int T;
int n, m, L, V, tot, tc, tf;
int d[N], v[N], a[N], p[N], s[N*5];
int temp[N*5];
bool del[N];
struct node{
    int l, r;
}b[N<<1], c[N<<1];
ll sq(ll x){return x*x;}
node getr(int i){
    //printf("i = %d, v[i] = %d, a[i] = %d\n", i, v[i], a[i]);
    if(a[i]==0){
        //printf("111\n");
        if(v[i]>V) return {d[i], L};
        else return {-1, -1};
    }else if(a[i]>0){
        //printf("222\n");
        ll dv = sq(V) - sq(v[i]);
        int loc = double(1.0) * dv / (2 * a[i]) + 1;
        if(d[i]+loc<=L) return {d[i]+loc, L};
        else return {-1, -1};
    }else{
        //printf("333\n");
        if(v[i]<=V) return {-1, -1};
        ll dv = sq(V) - sq(v[i]);
        int loc = double(1.0) * dv / (2 * a[i]);
        if(dv%(2*a[i])==0) --loc;
        //int stop = double(1.0) * sq(v[i]) / (2 * a[i]);
        //printf("d = %d, loc = %d\n", d[i], loc);
        return {d[i], min(L, d[i]+loc)};
    }
}
struct line{
    int tp;
    int loc, id;
}f[N*4];
queue<int> q;
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n >> m >> L >> V;
        for(int i=1; i<=n; ++i){
            cin >> d[i] >> v[i] >> a[i];
            //cout << "a[i] = "<<a[i]<<endl;4
            b[i] = getr(i);
            if(b[i].l>b[i].r) continue;
            if(b[i].l>0) temp[++tot] = b[i].l;
            if(b[i].r>0) temp[++tot] = b[i].r;
            //printf("now = %d\nrange : %d - %d\n", i, b[i].l, b[i].r);
        }
        for(int i=1; i<=m; ++i)
            cin >> p[i], temp[++tot] = p[i];
        sort(temp+1, temp+tot+1);
        int num = unique(temp+1, temp+tot+1) - temp - 1;
        //cout << "num = "<<num<<endl;
        for(int i=1; i<=n; ++i){
            if(b[i].l>=0){
                b[i].l = lower_bound(temp+1, temp+num+1, b[i].l)-temp;
                b[i].r = lower_bound(temp+1, temp+num+1, b[i].r)-temp;
            }
        }
        for(int i=1; i<=m; ++i)
            p[i] = lower_bound(temp+1, temp+num+1, p[i])-temp,
            ++s[p[i]], f[++tf] = {1, p[i], i};
            //printf("p %d = %d\n", i, p[i]);
        for(int i=1; i<=num; ++i) s[i] += s[i-1];
        for(int i=1; i<=n; ++i){
            if(s[b[i].r]-s[b[i].l-1])
                c[++tc] = b[i],
                f[++tf] = {0, b[i].l, i},
                f[++tf] = {2, b[i].r, i};
                //printf("l = %d, r = %d\n", b[i].l, b[i].r);
        }cout << tc << ' ';
        sort(f+1, f+tf+1, [](line x, line y){
            if(x.loc==y.loc)
                return x.tp < y.tp;
            return x.loc < y.loc;
        });
        int ans = 0, now = 0;

        for(int i=1; i<=tf; ++i){
            if(f[i].tp==2){
                if(del[f[i].id]) continue;
                ++ans;
                //printf("cut %d\n", f[i].id);
                while(q.size() && b[q.front()].l<=p[now]){
                    del[q.front()] = 1;
                    q.pop();
                    if(q.size()==0) break;
                }now = 0;
            }else if(f[i].tp==0){
                //printf("insert(%d)\n", f[i].id);
                //printf("lll%d, rrr%d\n", b[f[i].id].l, b[f[i].id].r);
                q.push(f[i].id);
            }else{
                now = f[i].id;
            }
        }
        cout << m - ans << '\n';
        tf = tc = tot = 0;
        memset(s, 0, sizeof(s));
        memset(del, 0, sizeof(del));
        while(!q.empty()) q.pop();
    }return 0;
}