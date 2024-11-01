#include <bits/stdc++.h>
using namespace std;
int T;
int s0[100005],a[100005],v0[100005];
long long d[400005],b[400005];
int p[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    while(T--){
        int n,m,L,V;
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++) cin >> s0[i] >> v0[i] >> a[i];
        for(int i = 1; i <= m; i++) cin >> p[i];
        int sum = n;
        if(m == 0){
            cout << "0 0" << endl;
            continue;
        }
        if(a[1] == 0){
            int maxx = 0;
            for(int i = 1; i <= n; i++){
                if(v0[i] <= V) sum--;
                else if(v0[i] > V){
                    if(s0[i]> p[m])sum--;
                    else{
                        if(maxx < s0[i]) maxx=s0[i];
                    }
                }
            }
            if(sum == 0) cout << sum << " " << m << endl;
            else cout << sum << " " << m-1 << endl;
        }
        else if(a[1] > 0){
            for(int i = 1; i <= n; i++){
                if(v0[i] > V){
                    if(s0[i]>p[m])sum--;
                }else {
                    double t = (double)(V-v0[i])/(double)a[i];
                    double sm = (double)s0[i] + ((double)v0[i])*t + 0.500000*((double)a[i])*t*t;
                    if(sm > (double)p[m]) sum--;
                }
            }
            if(sum == 0) cout << sum << " " << m << endl;
            else cout << sum << " " << m-1 << endl;
        }
        for(int i = 1; i <= n; i++) s0[i] = v0[i] = a[i] = 0;
        for(int i = 1; i <= m; i++) p[i] = 0;
    }
    return 0;
}
