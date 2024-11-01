#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
double T, n, m, L, V, ans;
double d[N], v[N], a[N], p[N];
bool mk[N];
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while(T--){
        memset(mk, 0, sizeof mk);
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++){
            cin >> d[i] >> v[i] >> a[i];
            if(v[i] > V) mk[i] = 1;
            else if((V*V-v[i]*v[i])/2/a[i]+d[i] <= L) mk[i] = 1, d[i] += (V*V-v[i]*v[i])/2/a[i] + 0.0000001;
        }
        for(int i = 1; i <= m; i++){
            cin >> p[i];
            if(i == m){
                for(int j = 1; j <= n; j++){
                    if(mk[j] && d[j] <= p[i]){
                        ans++;
                    }
                }
            }
        }
        cout << ans << ' ' << m - 1 << endl;

    }
    return 0;
}

