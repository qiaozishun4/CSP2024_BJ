#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int d[N], a[N], v[N], f[N];
int p[N], vis[N];

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        long long n, m, L, V;
        cin >> n >> m >> L >> V;
        for(int i=1;i<=n;i++){
            cin >> d[i] >> v[i] >> a[i];
            f[i] = 0;
        }
        for(int i=1;i<=m;i++){
            cin >> p[i];
        }

        int ans = 0, cnt = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j] >= d[i]){
                    long long  sspeed = 1LL*v[i]*v[i]+2LL*a[i]*(p[j]-d[i]);
                    if(1LL*V*V < sspeed){
                        f[i] = j;
                        if(a[i] >= 0){
                            cnt = 1;
                            break;
                        }
                        //cout << i << '\n';
                    }else{
                        if(a[i] <= 0) break;
                    }
                }
            }
        }

        for(int i=1;i<=n;i++){
            if(f[i] == 0) continue;
            ans++;
            
        }
        cout << ans << ' ' << m-cnt << '\n';
    }
    return 0;
}