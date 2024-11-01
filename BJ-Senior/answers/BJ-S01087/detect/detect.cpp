#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node{
    int d,v,a;
}c[N];
int p[N];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n,m,l,V;
        cin >> n >> m >> l >> V;
        bool flag_a = 1,flag_b = 1,flag_c = 1;
        for (int i = 1 ; i <= n ; i++){
            cin >> c[i].d >> c[i].v >> c[i].a;
            if (c[i].a != 0) flag_a = 0;
            if (c[i].a <= 0) flag_b = 0;
            if (c[i].a >= 0) flag_c = 0;
        }
        for (int i = 1 ; i <= m ; i++){
            cin >> p[i];
        }
        int cnt = 0;
        if (flag_a){
            for (int i = 1 ; i <= n ; i++){
                if (c[i].v > V && c[i].d <= p[m]){
                    cnt++;
                }
            }
            cout << cnt << " ";
            if (cnt == 0) cout << m << endl;
            else cout << m - 1 << endl;
        }
        else if (flag_b){
            for (int i = 1 ; i <= n ; i++){
                int s = l - c[i].d;
                double v_now = sqrt(c[i].v + 2.000 * c[i].a * s);
                if (v_now > V && c[i].d <= p[m]){
                    cnt++;
                }
            }
            cout << cnt << " ";
            if (cnt == 0) cout << m << endl;
            else cout << m - 1 << endl;
        }
        else if (flag_c){
            for (int i = 1 ; i <= n ; i++){
                if (c[i].d > p[m]) break;
                for (int j = 1 ; j <= m ; j++){
                    if (p[j] >= c[i].d){
                        int s = p[j] - c[i].d;
                        double v_now = max(0.0,sqrt(c[i].v + 2.000 * c[i].a * s));
                        if (v_now > V){
                            cnt++;
                        }
                        break;
                    }
                }
            }
            cout << cnt << " ";
            if (cnt == 0) cout << m << endl;
            else cout << m - 1 << endl;
        }
    }
    return 0;
}
