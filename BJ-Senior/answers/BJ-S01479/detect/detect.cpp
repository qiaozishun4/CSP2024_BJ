#include <iostream>
#include <cmath>
#define int long long
using namespace std;

int n, m, L, V;
int d[100010], v[1000010],  a[100010],  p[100010];
signed main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        bool flag1 = 1, flag2 = 1, flag3 = 1;
        cin >> n >> m >> L >>V;
        for(int i = 1; i <= n; i++){
            cin >>d[i] >>v[i] >>a[i];
            if(a[i] != 0){
                flag1 = 0;
            }
            if(a[i] < 0){
                flag2 = 0;
            }
            if(a[i] > 0){
                flag3 = 0;
            }

        }
        for(int i = 1; i <= m; i++){
            cin >>p[i];
        }
        if(flag1){
            int ans = 0;
            for(int i = 1; i <= n; i++){
                if(v[i] > V){
                    if(d[i] <= p[m]){
                        ans++;
                    }
                }
            }
            cout << ans << ' ' << m - 1 <<endl;
        }else if(flag2){
            int ans = 0;
            for(int i = 1; i <= n; i++){
                    if(d[i] > p[m]){
                        continue;
                    }
                    //(V * V - v[i] * v[i]) * 1.0 / (2.0 * a[i]) + 1.0 * d[i] < 1.0 *p[m]
                if((V * V - v[i] * v[i]) * 1.0 / (2.0 * a[i]) + 1.0 * d[i] < 1.0 *p[m]){
                    ans++;
                }
            }
            cout << ans << ' ' << m - 1 << endl;
        }else if(flag3){

        }

    }
    return 0;
}
