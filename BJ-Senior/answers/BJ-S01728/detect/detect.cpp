#include <bits/stdc++.h>

using namespace std;
int n, m, l, v, p[3005], s[3005], sv[3005], av[3005], t, cnt;
bool fl;
double e[3005];
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    for(int h = 0;h < t;h++){
        cin >> n >> m >> l >> v;
        for(int i = 0;i < n;i++){
            cin >> s[i] >> sv[i] >> av[i];
        }
        for(int i = 0;i < m;i++){
            cin >> p[i];
        }
        for(int i = 0;i < n;i++){
            fl = 0;
            for(int j = 0;j < m;j++){
                if(s[i] <= p[j]){
                    e[i] = sqrt(v * v + 2 * av[i] * (p[j] - s[i]));
                    if(e[i] > v){
                        fl = 1;
                    }
                    cout << e[i] << ' ';
                    break;
                }
            }
            if(fl){
                ++cnt;
            }
        }

        cout << cnt << '\n';
        cnt = 0;
    }


    return 0;
}
