#include <bits/stdc++.h>
using namespace std;
int T, n, m, L, V, d[100005] = {}, v[100005] = {}, a[100005] = {}, p[100005] = {};
int main(){
    freopen("detect.in","r", stdin);
    freopen("detect.out","w", stdout);
    cin >>T;
    while(T--){
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++){
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i = 1; i <= m; i++){
            cin >> p[i];
        }
        int ans = 0, tong[200005] = {}, minn[200005] = {};
        for(int i = 1; i <= n; i++){
            minn[i] = 1000000;
            if(a[i] == 0 && v[i] > V){
                    ans++;
                for(int j = d[i]; j <= m; j++){
                    if(d[i] < p[j]){
                        tong[p[j]]++;
                        if(minn[i] > p[j]) minn[i] = p[j];
                    }
                }
            }
        }
        cout << ans << " " << ans;
        bool flag = true;
        for(int i = 1; i <= L; i++){
            if(tong[i] == 3) cout << m-1;
            else if(tong[i] == 2){
                flag = false;

            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}