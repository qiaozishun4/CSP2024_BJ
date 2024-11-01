#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T, n, m, L, V, ans1, ans2, p[100010];
bool flag = 1;
struct Enterprise {
    ll d, a, v;
} uss[100010];
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> m >> L >> V;
        for(ll i = 1; i <= n; i++) cin >> uss[i].d >> uss[i].v >> uss[i].a;
        for(ll i = 1; i <= m; i++) cin >> p[i];
        ans1 = 0, ans2 = 0;
        for(ll i = 1; i <= n; i++) {
            if(uss[i].a==0) {
                if(uss[i].v>V&&uss[i].d<=p[m]) {
                    ans1++;
                }
            }
            else if(uss[i].a>0) {
                if((uss[i].v*uss[i].v+2*uss[i].a*(p[m]-uss[i].d))>V*V&&uss[i].d<=p[m]) {
                    ans1++;
                }
            }
            else {
                for(ll j = 1; j <= m; j++) {
                    if(p[j]>=uss[i].d) {
                        if((uss[i].v*uss[i].v+2*uss[i].a*(p[j]-uss[i].d))>V*V) {
                            if(j!=m) ans2++;
                            flag = 0;
                            ans1++;
                            break;
                        }
                    }
                }
            }
        }
        cout << ans1 << ' ';
        if(flag) {
            if(ans1==0) cout << m << '\n';
            else cout << m-1 << '\n';
        }
        else cout << m-ans2-1 << '\n';
    }
    return 0;
}