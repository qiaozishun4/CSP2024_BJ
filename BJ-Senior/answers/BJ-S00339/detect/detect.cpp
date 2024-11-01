#include <bits/stdc++.h>
using namespace std;
int t, n, m;
long long len, limv, d[100005], v[100005], a[100005], p[100005];
struct node{
    int lp, rp;
    inline bool operator <(const node o)const{
        return rp < o.rp;
    }
}seg[100005];
inline bool chk(int i, long long x){
    if(1 <= x && x <= m && p[x] < d[i]){
        return 0;
    }
    long long nowv2 = v[i] * v[i] + 2 * a[i] * (p[x] - d[i]);
    return nowv2 > limv * limv;
}
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //double st = clock();
    cin >> t;
    while(t--){
        memset(p, 0, sizeof(p));
        cin >> n >> m >> len >> limv;
        for(int i = 1;i <= n;i++){
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i = 1;i <= m;i++){
            cin >> p[i];
        }
        int ans1 = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] > 0){
                int l = 1, r = m + 1, mid;
                while(l < r){
                    mid = (l + r)/ 2;
                    if(chk(i, mid)){
                        r = mid;
                    }
                    else{
                        l = mid + 1;
                    }
                }
                seg[i].lp = l;
                seg[i].rp = m;
            }
            else if(a[i] == 0){
                if(v[i] <= limv){
                    seg[i].lp = 0;
                    seg[i].rp = -1;
                    continue;
                }
                seg[i].lp = lower_bound(p + 1, p + m + 1, d[i]) - p;
                seg[i].rp = m;
            }
            else{
                int be = lower_bound(p + 1, p + m + 1, d[i]) - p;
                int l = be - 1, r = m, mid;
                while(l < r){
                    mid = (l + r + 1)/ 2;
                    //cerr << "erfen " << l << " " << r << " " << p[mid] << " " << i << " " << chk(i, p[mid]) << "\n";
                    if(chk(i, mid)){
                        l = mid;
                    }
                    else{
                        r = mid - 1;
                    }
                }
                seg[i].lp = be;
                seg[i].rp = l;
            }
            //cerr << seg[i].lp << " " << seg[i].rp << "\n";
            if(seg[i].lp <= seg[i].rp){
                ans1++;
            }
        }
        sort(seg + 1, seg + n + 1);
        int lst = -1, ans2 = 0;
        for(int i = 1;i <= n;i++){
            if(seg[i].lp > seg[i].rp){
                continue;
            }
            if(seg[i].lp <= lst && lst <= seg[i].rp){
                continue;
            }
            lst = seg[i].rp;
            ans2++;
        }
        cout << ans1 << " " << m - ans2 << "\n";
    }
    //cerr << (clock() - st)/ CLOCKS_PER_SEC << "\n";
    return 0;
}
