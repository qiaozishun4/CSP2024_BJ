#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
int t, n;
long long a[200005];
struct node{
    int l, r;
    long long mx, lazy;
    node(){
    }
    node(int _l, int _r){
        l = _l;
        r = _r;
        mx = -inf;
        lazy = 0;
    }
}sf[5000005], sg[5000005];
void build(int x, int l, int r){
    sf[x] = sg[x] = node(l, r);
    if(l == r){
        if(l == 0){
            sf[x].mx = sg[x].mx = 0;
        }
        return;
    }
    int mid = (l + r)/ 2;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    sf[x].mx = max(sf[x * 2].mx, sf[x * 2 + 1].mx);
    sg[x].mx = max(sg[x * 2].mx, sg[x * 2 + 1].mx);
}
inline void pushdownf(int x){
    if(sf[x].lazy){
        sf[x * 2].mx += sf[x].lazy;
        sf[x * 2].lazy += sf[x].lazy;
        sf[x * 2 + 1].mx += sf[x].lazy;
        sf[x * 2 + 1].lazy += sf[x].lazy;
        sf[x].lazy = 0;
    }
}
inline void pushdowng(int x){
    if(sg[x].lazy){
        sg[x * 2].mx += sg[x].lazy;
        sg[x * 2].lazy += sg[x].lazy;
        sg[x * 2 + 1].mx += sg[x].lazy;
        sg[x * 2 + 1].lazy += sg[x].lazy;
        sg[x].lazy = 0;
    }
}
void modifyf(int x, int l, int r, long long v){
    if(l <= sf[x].l && sf[x].r <= r){
        sf[x].mx += v;
        sf[x].lazy += v;
        return;
    }
    int mid = (sf[x].l + sf[x].r)/ 2;
    if(l <= mid){
        modifyf(x * 2, l, r, v);
    }
    if(mid < r){
        modifyf(x * 2 + 1, l, r, v);
    }
    sf[x].mx = max(sf[x * 2].mx, sf[x * 2 + 1].mx);
}
void modifyg(int x, int l, int r, long long v){
    if(l <= sg[x].l && sg[x].r <= r){
        sg[x].mx += v;
        sg[x].lazy += v;
        return;
    }
    int mid = (sg[x].l + sg[x].r)/ 2;
    if(l <= mid){
        modifyg(x * 2, l, r, v);
    }
    if(mid < r){
        modifyg(x * 2 + 1, l, r, v);
    }
    sg[x].mx = max(sg[x * 2].mx, sg[x * 2 + 1].mx);
}
long long askf(int x, int l, int r){
    if(l <= sf[x].l && sf[x].r <= r){
        return sf[x].mx;
    }
    int mid = (sf[x].l + sf[x].r)/ 2;
    long long ans = -inf;
    pushdownf(x);
    if(l <= mid){
        ans = max(ans, askf(x * 2, l, r));
    }
    if(mid < r){
        ans = max(ans, askf(x * 2 + 1, l, r));
    }
    return ans;
}
long long askg(int x, int l, int r){
    if(l <= sg[x].l && sg[x].r <= r){
        return sg[x].mx;
    }
    int mid = (sg[x].l + sg[x].r)/ 2;
    long long ans = -inf;
    pushdowng(x);
    if(l <= mid){
        ans = max(ans, askg(x * 2, l, r));
    }
    if(mid < r){
        ans = max(ans, askg(x * 2 + 1, l, r));
    }
    return ans;
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    //double st = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        build(1, 0, 1000005);
        for(int i = 1;i <= n;i++){
            long long nowf = max(askg(1, a[i], a[i]) + a[i], 
                           max(askg(1, 0, a[i] - 1), askg(1, a[i] + 1, 1000005)));
            long long nowg = max(max(askg(1, a[i - 1], a[i - 1]), askf(1, a[i], a[i]) + a[i]), 
                           max(askf(1, 0, a[i] - 1), askf(1, a[i] + 1, 1000005)));
            if(a[i - 1] == a[i]){
                modifyf(1, 0, 1000005, a[i]);
                modifyg(1, 0, 1000005, a[i]);
            }
            nowf = max(nowf, askf(1, a[i - 1], a[i - 1]));
            nowg = max(nowg, askg(1, a[i - 1], a[i - 1]));
            modifyf(1, a[i - 1], a[i - 1], nowf - askf(1, a[i - 1], a[i - 1]));
            modifyg(1, a[i - 1], a[i - 1], nowg - askg(1, a[i - 1], a[i - 1]));
        }
        cout << max(askf(1, 0, 1000005), askg(1, 0, 1000005)) << "\n";
    }
    //cerr << (clock() - st)/ CLOCKS_PER_SEC << "\n";
    return 0;
}
