#include<bits/stdc++.h>
using namespace std;
int T;
bool r[100005];
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while(T--) {
        int n, m, L, V, sum = 0, cnt = 0;
        int d[100005], v[100005], a[100005], p[100005];
        cin >> n >> m >> L >> V;
        for(int i = 0; i < n; i++) {
            cin >> d[i] >> v[i] >> a[i];
            r[i] = true;
        }
        for(int i = 0; i < m; i++) cin >> p[i];
        for(int i = 0; i <= m; i++) {
            bool flag = true;
            for(int j = 0; j < n; i++) {
                if(d[j] <= p[i]) {
                    float k = sqrt(v[i]*v[i]+2*a[i]*(p[i]-d[j]));
                    if(k > V && r[j] == true) {
                        r[j] = false;
                        sum++;
                        flag = true;
                    }
                }
                if(flag == true) cnt++;
            }
        }
        cout << sum << " " << cnt << endl;
    }
    return 0;
}
