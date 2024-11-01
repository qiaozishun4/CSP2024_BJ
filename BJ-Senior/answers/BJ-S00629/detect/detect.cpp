#include<bits/stdc++.h>
using namespace std;
int d[100010], a[100010], v[100010];
int as2[100010], vis[100010];
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    for(int h = 1; h <= t; h++){
        int n, m, l, V;
        cin >> n >> m >> l >> V;
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            cin >> d[i] >> v[i] >> a[i];
            as2[i] = V * V - v[i] * v[i];
        }
        int p;
        for(int i = 1; i <= m; i++){
            cin >> p;
            vis[p] = 1;
        }
        int cnt = 0, ans = 0;
        for(int i = 1; i <= n; i++){
            bool flag = 0;
            if(a[i] < 0 && v[i] > V){
                //cout << as2[i] * 1.0 / (2 * a[i]) << endl;
                for(int cur = d[i]; cur < min(d[i] + as2[i] * 1.0 / (2 * a[i]), l * 1.0); cur++){
                    if(vis[cur]){
                        vis[cur]++;
                        flag = 1;
                    }
                }
                if(flag) cnt++;
            }
            else if(a[i] > 0){
                //cout << as2[i] * 1.0 / (2 * a[i]) << endl;
                for(int cur = d[i] + int(as2[i] * 1.0 / (2 * a[i])) + 1; cur <= l; cur++){
                    if(vis[cur]){
                        vis[cur]++;
                        flag = 1;
                    }
                }
                if(flag) cnt++;
            }
            else if(a[i] == 0 && v[i] > V){
                for(int cur = d[i]; cur <= l; cur++){
                    if(vis[cur]){
                        vis[cur]++;
                        flag = 1;
                    }
                }
                if(flag) cnt++;
            }
        }
        //cout << num[2] << num[3] << num[4] << endl;
        for(int j = 1; j <= l; j++){
            if(vis[j] == cnt) ans++;
        }
        cout << cnt << " " << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}