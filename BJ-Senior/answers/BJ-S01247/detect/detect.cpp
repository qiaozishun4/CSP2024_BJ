#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e5 + 5;

int T;
ll d[N], v[N], a[N];
ll p[N];
ll n, m, L, V;
ll k[N][2];
ll dis;
ll q[N][2], top;
bool f[N];
ll ans;
ll num[N];

ll find1(ll l, ll r, ll x){
    return ll(upper_bound(p+l, p+r+1, x) - p);
}

ll find2(ll l, ll r, ll x){
    return ll(lower_bound(p+l, p+r+1, x) - p);
}

//void dfs(ll k, ll step){
//    if(k==0){
//        ans = min(ans, step);
//        return;
//    }
//    ll ma = 0, idx[N], tp = 0;
//    ll idx2[N], tp2 = 0;
//    for(ll i=1; i<=m; i++){
//        if(num[i]>ma){
//            tp = 1;
//            idx[tp] = i;
//            ma = num[i];
//        }else if(num[i]==ma){
//            idx[++tp] = i;
//        }
//    }
//    for(ll i=1; i<=tp; i++){
//        for(ll j=1; j<=top; j++){
//            if(f[j] && idx[i]>=q[j][0] && idx[i]<=q[j][1]){
//                idx2[++tp2] = j;
//                f[j] = true;
//                for(ll l=q[j][0]; l<=q[j][1]; l++){
//                    num[l]--;
//                }
//            }
//        }
//        dfs(k-tp2, step+1);
//        for(ll j=1; j<=tp2; j++){
//            f[idx[j]] = false;
//            for(ll l=q[idx[j]][0]; l<=q[idx[j]][1]; l++){
//                num[l]++;
//            }
//        }
//        tp2 = 0;
//    }
//}

void dfs(ll k, ll step){
    if(k==m+1){
        bool flag = false;
        for(int i=1; i<=top; i++){
            if(!f[i]) flag = true;
        }
        if(!flag) ans = min(ans, step);
        return;
    }
    dfs(k+1, step);
    int idx[N], tp = 0;
    for(int i=1; i<=top; i++){
        if(q[i][0]<=k && q[i][1]>=k){
            f[i] = true;
            idx[++tp] = i;
        }
    }
    dfs(k+1, step+1);
    for(int i=1; i<=tp; i++){
        f[idx[i]] = false;
    }
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        memset(f, 0, sizeof(f));
        scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
        for(ll i=1; i<=n; i++){
            scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
        }
        for(ll i=1; i<=m; i++){
            scanf("%lld", &p[i]);
            f[p[i]] = true;
        }
        sort(p+1, p+m+1);
        for(ll i=1; i<=n; i++){
            ll t = find2(1, m, d[i]);
            if(a[i]>0){
                dis = max(0ll, ll(V * V - v[i] * v[i]) / a[i] / 2 + ll((V * V - v[i] * v[i]) % (a[i] * 2) != 0));
                k[i][0] = find1(t, m, dis+d[i]);
                k[i][1] = m;
                if(k[i][0]>k[i][1]) k[i][0] = k[i][1] = -1;
            }else if(a[i]<0){
                dis = max(0ll, ll(V * V - v[i] * v[i]) / a[i] / 2);
                k[i][0] = t;
                k[i][1] = find2(t, m, dis+d[i]) - 1;
                if(k[i][0]>k[i][1]) k[i][0] = k[i][1] = -1;
            }else{
                if(v[i]>V){
                    k[i][0] = t;
                    k[i][1] = m;
                }else if(v[i]<=V){
                    k[i][0] = k[i][1] = -1;
                }
            }
        }
        top = 0;
        for(ll i=1; i<=n; i++){
            if(k[i][0]!=-1){
                top++;
                q[top][0] = k[i][0];
                q[top][1] = k[i][1];
            }
        }
        printf("%lld ", top);
//        for(ll i=1; i<=top; i++){
//            for(ll j=q[i][0]; j<=q[i][1]; j++){
//                num[j]++;
//            }
//        }
        ans = m;
        dfs(1, 0);
        printf("%lld\n", m-ans);
    }

    return 0;
}
