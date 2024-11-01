#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 1e5 + 5;
const int L = 1e6 + 5;
const int V = 1e3 + 5;
int T;
int n, m, len, vmax;
long double d[N], v[N], a[N];
long double l[N], r[N], p[N];
int main(){
    //freopen("detection","r",stdin);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>len>>vmax;
        for(int i = 1; i <= n; i++) cin>>d[i]>>v[i]>>a[i];
        for(int i = 1; i <= m; i++) cin>>p[i];
        if(a[1] == 0){
            int ans = 0;
            for(int i = 1; i <= n; i++){
                if(v[i] > vmax && d[i] <= p[m]) ans++;
            }
            if(ans == 0) cout<<0<<" "<<m<<endl;
            else cout<<ans<<" "<<m - 1<<endl;
        }
        if(a[1] > 0){
            int ans = 0;
            for(int i = 1; i <= n; i++){
                if(v[i] > vmax && d[i] <= p[m]) ans++;
                else if(1.0 * (vmax * vmax - v[i] * v[i]) / (2 * a[i]) + 1.0 * d[i] < p[m]) ans++;
            }
            if(ans == 0) cout<<0<<" "<<m<<endl;
            else cout<<ans<<" "<<m - 1<<endl;
        }
    }
    return 0;
}
