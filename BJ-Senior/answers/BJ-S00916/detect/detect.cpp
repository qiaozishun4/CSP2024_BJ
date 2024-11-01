#include <iostream>
#include <cmath>
using namespace std;

typedef long double db;

const int maxn = 100005;

int v[maxn], d[maxn], a[maxn], p[maxn], n, m, L, V, T;

struct Node{
    int l, r, sum, lazy;
}t[maxn<<2];

void build(int id, int l, int r){
    t[id] = {l, r, 0, 0};
    if (l == r) return;
    int mid = (l+r)/2;
    build(id<<1, l, mid);
    build(id<<1|1, mid+1, r);
}

void pushdown(int id){
    if (t[id].lazy){
        t[id<<1].lazy += t[id].lazy;
        t[id<<1|1].lazy += t[id].lazy;
        t[id].sum += t[id].lazy*(t[id].r-t[id].l+1);
        t[id].lazy = 0;
    }
}

void change(int id, int l, int r, int c){
    if (t[id].l == l && t[id].r == r){
        t[id].lazy += c;
        return;
    }
    pushdown(id);
    if (t[id<<1].r >= r) change(id<<1, l, r, c);
    else if (t[id<<1|1].l <= l) change(id<<1|1, l, r, c);
    else{
        change(id<<1, l, t[id<<1].r, c);
        change(id<<1|1, t[id<<1|1].l, r, c);
    }
    t[id].sum = t[id<<1].sum+t[id<<1].lazy*(t[id<<1].r-t[id<<1].l+1)+t[id<<1|1].sum+t[id<<1|1].lazy*(t[id<<1|1].r-t[id<<1|1].l+1);
}

int query(int id, int l, int r){
    if (t[id].l == l && t[id].r == r){
        return t[id].sum+t[id].lazy*(t[id].r-t[id].l+1);
    }
    pushdown(id);
    if (t[id<<1].r >= r) return query(id<<1, l, r);
    else if (t[id<<1|1].l <= l) return query(id<<1|1, l, r);
    return query(id<<1, l, t[id<<1].r)+query(id<<1|1, t[id<<1|1].l, r);
}

void solve(){
    cin >> n >> m >> L >> V;
    int cnt = 0, ans = 0;
    bool mark[maxn];
    for (int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
    for (int i = 1; i <= m; i++) cin >> p[i];
    build(1, 1, m);
    for (int i = 1; i <= n; i++){
        int l1 = 1, r1 = m;
        while (l1 <= r1){
            int mid = (l1+r1)/2;
            if (p[mid] < d[i]) l1 = mid+1;
            else r1 = mid-1;
        }
        //cout << "car no." << i << " can be detected after " << l1 << " \n";
        if (a[i] == 0 && v[i] > V && d[i] <= p[m]){
            //cout << "car no." << i << " is overspeed, detected by after " << l1 << " \n";
            if (query(1, l1, m) == 0){
                change(1, l1, m, 1);
                ans++;
            }
            cnt++;
        }
        if (a[i] > 0){
            int l = l1, r = m;
            while (l <= r){
                int mid = (l+r)/2;
                db v1 = sqrt(v[i]*v[i]+2*a[i]*(p[mid]-d[i]));
                if (v1 <= V) l = mid+1;
                else r = mid-1;
            }
            if (l <= m){
                //cout << "car no." << i << " is overspeed, detected by after " << l << " \n";
                if (query(1, l, m) == 0){
                    change(1, l, m, 1);
                    ans++;
                }
                cnt++;
            }
        }
        if (a[i] < 0){
            int l = l1, r = m;
            db xx = d[i]-(v[i]*v[i])/(2*a[i]);
            while (l <= r){
                int mid = (l+r)/2;
                db v1 = sqrt(v[i]*v[i]+2*a[i]*(p[mid]-d[i]));
                if (p[mid] > d[i]+xx) r = mid-1;
                if (v1 > V) l = mid+1;
                else r = mid-1;
            }
            if (r >= l1){
                //cout << "car no." << i << " is overspeed, detected by before " << r << " \n";
                if (query(1, l1, r) == 0){
                    change(1, l1, r, 1);
                    ans++;
                }
                cnt++;
            }
        }
    }
    cout << cnt << " " << m-ans << "\n";
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
