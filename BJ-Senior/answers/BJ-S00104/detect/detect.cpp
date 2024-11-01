#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, M = 1e6 + 5;
int T, n, m, L, V, pos[N], ans1, ans2, nxt[M];
struct Node{
    int l, r;
    bool operator <(Node &x){
        if(l != x.l)return l < x.l;
        return r < x.r;
    }
}lim[N];
struct Car{
    int d, v, delta;
}a[N];
bool check(int x, Car c){
    int s = x - c.d;
    if(s < 0)return 0;
//    if(c.delta < 0 && c.v * c.v < 2 * s * abs(c.delta))return 0;
    if(c.delta == 0)return (c.v > V);
    return (c.v * c.v + 2 * c.delta * s > V * V);
}
int binary(int x, bool typ){ //1:max 0:min
    int l = nxt[a[x].d], r = m, res = 0;
    while(l <= r){
        int mid = (l + r) / 2;
//        cout << "check(" << pos[mid] << ", " << x << ")=" << check(pos[mid], a[x]) << '\n';
        if(check(pos[mid], a[x])){
            res = mid;
            if(typ)l = mid + 1;
            else r = mid - 1;
        }else{
            if(a[x].delta < 0){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
    }
    return res;
}
void get(bool typ){
    for(int i = 1;i <= n;i++){
        if(typ){
            lim[i].r = binary(i, 1);
        }else{
            lim[i].l = binary(i, 0);
        }
    }
}
signed main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        memset(nxt, 0, sizeof nxt);
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++){
            cin >> a[i].d >> a[i].v >> a[i].delta;
        }
        for(int i = 1;i <= m;i++){
            cin >> pos[i];
            nxt[pos[i]] = i;
        }
        for(int i = L;i >= 0;i--){
            if(!nxt[i])nxt[i] = nxt[i + 1];
        }
        get(0), get(1);
        ans1 = ans2 = 0;
        for(int i = 1;i <= n;i++){
//            cout << "[" << lim[i].l << ", " << lim[i].r << "]\n";
            if(lim[i].l){
                ans1++;
            }
        }
        sort(lim + 1, lim + n + 1);
        int nr = 0;
        for(int i = 1;i <= n;i++){
            if(!lim[i].l)continue;
            if(lim[i].l > nr)ans2++, nr = lim[i].r;
            else nr = min(nr, lim[i].r);
        }
        cout << ans1 << ' ' << m - ans2 << '\n';
    }
    return 0;
}
