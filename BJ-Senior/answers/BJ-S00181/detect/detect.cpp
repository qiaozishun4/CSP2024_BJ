#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
int d[N] , v[N] , a[N] , p[N] , s[N] , lst[N];
struct line{
    double l , r;
    bool operator <(const line &x){
        return r < x.r;
    }
} t[N];
int main(){
    freopen("detect.in" , "r" , stdin);
    freopen("detect.out" , "w" , stdout);
    int T;
    cin >> T;
    while (T--){
        memset(p , 0 , sizeof(p));
        int n , m , L , V;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)cin >> d[i] >> v[i] >> a[i];
        for (int i = 1; i <= m; i++){
            int x;
            cin >> x;
            p[x] = 1;
        }
        for (int i = 1; i <= L; i++){
            lst[i] = lst[i-1];
            if (p[i])lst[i] = i;
        }
        for (int i = 1; i <= L; i++)s[i] = s[i-1] + p[i];
        for (int i = 1; i <= n; i++){
            if (a[i] == 0){
                if (v[i] <= V)t[i].l = t[i].r = -1;
                else{
                    t[i].l = d[i];
                    t[i].r = L;
                }
            }
            else if(a[i] < 0){
                if (v[i] <= V)t[i].l = t[i].r = -1;
                else{
                    double ttt = d[i] + (V * V - v[i] * v[i]) / 2.0 / a[i];
                    //ttt = min(ttt , d[i] - v[i] * 1.0 / a[i]);
                    ttt = min(ttt , L * 1.0);
                    t[i].l = d[i];
                    t[i].r = ttt - 1e-6;
                }
            }
            else{
                if (v[i] >= V){
                    t[i].l = d[i];
                    t[i].r = L;
                }
                else{
                    double ttt = d[i] + (V * V - v[i] * v[i]) / 2.0 / a[i];
                    if (ttt > L)t[i].l = L + 1e-6;
                    else t[i].l = ttt + 1e-6;
                    t[i].r = L;
                }
            }
            //cout << i << ' ' << t[i].l << ' ' << t[i].r << endl;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (t[i].l == -1)continue;
            int t1 = floor(t[i].r) , t2 = ceil(t[i].l);
            int now = s[t1];
            if (t2 != 0)now -= s[t2-1];
            /*
            cout << i << ' ' << t1 << ' ' << t2 << endl;
            cout << s[t1] << ' '; 
            if (t2 != 0)cout << s[t2-1] << ' ';
            cout << now << endl;
            */
            if (now)cnt++;
        }
        sort (t + 1 , t + n + 1);
        int ls = -1e9 , ans = 0;
        for (int i = 1; i <= n; i++)
            if (t[i].l != -1){
                int t1 = floor(t[i].r) , t2 = ceil(t[i].l);
                int now = s[t1];
                if (t2 != 0)now -= s[t2-1];
                if (now == 0)continue;
                if (ls >= t2)continue;
                ls = lst[t1];
                //cout << t[i].l << ' ' << t[i].r << ' ' << ls << endl;
                ans++;
            }
        cout << cnt << ' ' << m - ans << '\n';
    }
    return 0;
}
//18.20