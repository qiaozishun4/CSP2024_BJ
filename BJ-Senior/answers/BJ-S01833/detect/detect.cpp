#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MaxN = 1e6 + 5;

ll T;
ll n, m, L, V, ans1 = 0, ans2 = 0;
bool flagA = 1, flagB = 1, flagC = 1;


struct car{
    ll d, v, a;
    car(){}
    car(ll x, ll  y, ll z){
        d = x, v = y, a = z;
    }
}cars[MaxN];

struct Node{
    ll d;
    bool isopen;
    Node(){}
    Node(ll x){
        d = x;
        isopen = true;
    }
}f[MaxN];

void init(){
    L = 0, V = 0, ans1 = 0, ans2 = 0;
    for (ll i = 1;i <= n;i ++) cars[i] = car(0, 0, 0);
    for (ll i = 1;i <= m;i ++) f[i] = Node(0);
    n = 0, m = 0;
    flagA = 1, flagB = 1, flagC = 1;
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T --){
        init();
        cin >> n >> m >> L >> V;
        for (ll i = 1;i <= n;i ++){
            ll x, y, z;
            cin >> x >> y >> z;
            if (z != 0) flagA = 0;
            if (z <= 0) flagB = 0;
            if (z >= 0) flagC = 0;
            cars[i] = car(x, y, z);
        }
        ll h1 = 0, h2 = 0;
        for (ll i = 1;i <= m;i ++){
            ll p;
            cin >> p;
            if (h1 < p) {
                h1 = p;
                h2 = i;
            }
            f[i] = Node(p);
        }

        if (flagA){
            ans2 = m - 1;
            for (ll i = 1;i <= n;i ++){
                if(cars[i].d <= f[h2].d && cars[i].v > V) ans1 ++;
            }
            if (ans1 == 0) ans2 = m;
            cout << ans1 << ' ' << ans2 << endl;
            continue;
        }

        if (flagB){
            ans2 = m - 1;
            for (ll i = 1;i <= n;i ++){
                if (cars[i].d > f[h2].d) continue;
                double vl = sqrt(cars[i].v * cars[i].v + 2 * cars[i].a * (f[h2].d - cars[i].d));
                if (vl > V) ans1 ++;
            }
            if (ans1 == 0) ans2 = m;
            cout << ans1 << ' ' << ans2 << endl;
            continue;
        }


        for (ll i = 1;i <= n;i ++){
            double vl = 0;
            if (cars[i].d > f[h2].d) continue;
            for (ll j = 1;j <= m;j ++){
                if (cars[i].d > f[j].d) continue;
                vl = sqrt(cars[i].v * cars[i].v + 2 * cars[i].a * (f[j].d - cars[i].d));
                if (vl > V) {
                    ans1 ++;
                    break;
                }
            }
        }

        for (ll i = 1;i <= m;i ++){
            f[i].isopen = false;
            ll ans3 = 0;
            ans2 ++;
            for (ll i = 1;i <= n;i ++){
                double vl = 0;
                if (cars[i].d > f[h2].d) continue;
                for (ll j = 1;j <= m;j ++){
                    if (cars[i].d > f[j].d) continue;
                    vl = sqrt(cars[i].v * cars[i].v + 2 * cars[i].a * (f[j].d - cars[i].d));
                    if (vl > V && f[j].isopen) {
                        ans3 ++;
                        break;
                    }
                }
            }
            if (ans1 != ans3) f[i].isopen = true, ans2 --;
        }
        cout << ans1 <<' ' << ans2 << endl;

    }
    return 0;
}
