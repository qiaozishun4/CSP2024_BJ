#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int d, v, a;
}data[100005];
int p[100005];
bool vis[100005];
signed main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        memset(p, 0, sizeof p);
        memset(vis, true, sizeof vis);
        int n, m, l, v;
        cin >> n >> m >> l >> v;
        bool flag = true, flag1 = true, flag2 = true;
        for(int i = 1;i <= n;i++){
            cin >> data[i].d >> data[i].v >> data[i].a;
            if(data[i].a != 0) flag = false;
            if(data[i].a < 0) flag1 = false;
            if(data[i].a > 0) flag2 = false;
        }
        for(int i = 1;i <= m;i++) cin >> p[i];
        if(flag){
            int ans = 0;
            for(int i = 1;i <= n;i++){
                bool flag = false;
                for(int j = 1;j <= m;j++){
                    if(p[j] >= data[i].d && v < data[i].v){
                        flag = true;
                        vis[j] = false;
                        break;
                    }
                }
                if(flag) ans++;
            }
            cout << ans << " ";
            int num = 0;
            for(int i = 1;i <= m;i++) if(vis[i]) num++;
            cout << num << endl;
            for(int i = 1;i <= n;i++) data[i].d = data[i].v = data[i].a = 0;
        }
        else if(flag1){
            int ans = 0;
            int j = 1;
            for(int i = 1;i <= n;i++){
                int d = data[i].d, v0 = data[i].v, a = data[i].a;
                bool flag = false;
                while(true){
                    double s = v0 * t + 0.5 * a * t * t;
                    if(d+s == p[j] && sqrt(v0 * v0 + 2 * a * s) > v){
                        flag = true;
                        vis[j] = true;
                        break;
                    }
                    else if(d + s > p[j]) j++;
                }
                if(flag) ans++;
            }
            cout << ans << " ";
            int num = 0;
            for(int i = 1;i <= m;i++) if(vis[i]) num++;
            cout << num << endl;
            for(int i = 1;i <= n;i++) data[i].d = data[i].v = data[i].a = 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
