#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
#define endl '\n'
#define int long long

const int MAXN = 1e5 + 10;
int t,n,m,l,v,p[MAXN],pos[MAXN];
struct Node{
    int d,v,a;
    bool operator<(const Node &a){
        return d < a.d;
    }
}a[MAXN];
struct Node1{
    int l,r;
    bool operator<(const Node1 &a) const {
        return r < a.r;
    }
}tx[MAXN];

signed main(){
    ios::sync_with_stdio(false);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n >> m >> l >> v;
        bool flag1 = 1,flag2 = 1;
        for(int i = 1;i <= n;++i){
            cin >> a[i].d >> a[i].v >> a[i].a;
            flag1 = flag1 && (a[i].a == 0);
            flag2 = flag2 && (a[i].a > 0);
        }
        for(int i = 1;i <= m;++i) cin >> p[i];
        if(flag1){
            int cnt = 0;
            for(int i = 1;i <= n;++i)
                if(a[i].v > v && a[i].d <= p[m]) cnt++;
            cout << cnt << ' ';
            if(cnt != 0) cout << m - 1 << endl;
            else cout << m << endl;
            continue;
        }
        if(flag2){
            int cnt = 0;
            for(int i = 1;i <= n;++i){
                if(a[i].d > p[m]) continue;
                double vx = sqrt(2 * a[i].a * (p[m] - a[i].d) + a[i].v * a[i].v);
                if(vx > v) cnt++;
            }
            cout << cnt << ' ';
            if(cnt == 0) cout << m << endl;
            else cout << m - 1 << endl;
            continue;
        }
        sort(a + 1,a + n + 1);
        int k = 1,len = 0;
        for(int i = 1;i <= n;++i) pos[i] = 0;
        for(int j = 1;j <= m;++j){
            while(k <= n && a[k].d <= p[j]) ++k;
            for(int i = 1;i < k;++i){
                int vx = (p[j] - a[i].d) * a[i].a * 2 + a[i].v * a[i].v;
                if(vx > v * v){
                    if(pos[i] == 0){
                        pos[i] = ++len;
                        tx[len] = {j,j};
                    }
                    else tx[pos[i]].r = j;
                }
            }
        }
        cout << len << ' ';
        sort(tx + 1,tx + len + 1);
        int last = tx[1].r,cnt = 1;
        for(int i = 2;i <= len;++i){
            if(last < tx[i].l){
                last = tx[i].r,cnt++;
            }
        }
        cout << m - cnt << endl;
    }
    return 0;
}
