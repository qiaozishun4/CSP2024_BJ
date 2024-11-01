#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int t, n, m, L, V;
int d[100005], v[100005], a[100005], p[100005];

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while(t--){
        memset(d, 0, sizeof(d));
        memset(v, 0, sizeof(v));
        memset(a, 0, sizeof(a));
        memset(p, 0, sizeof(p));
        cin >> n >> m >> L >> V;
        int maxp = -0x3f3f3f3f, maxa = -0x3f3f3f3f;
        int cnt1=0, c=0, cnt2=0;
        for(int i=1; i<=n; i++){
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i=1; i<=m; i++){
             cin >> p[i];
             maxa = max(maxa, p[i]);
        }
        for(int i=1; i<=n; i++){
            int ls, rs;
            float posn = (1.0*V*V-v[i]*v[i])/(2*a[i])+d[i];
            int pos = floor(posn);
            if(a[i]>0){
                ls = pos, rs = maxa;
            }
            else if(a[i]<0 && v[i]>V){
                ls = d[i], rs = pos;
            }
            else if(v[i] > V){
                ls = d[i], rs = maxa;
            }
            else ls = maxa+1, rs = -1;
            bool fl=0;
            for(int j=1; j<=m; j++){
                if(ls <= p[j] && rs >=p[j]){
                    fl = 1;
                    c++;
                }
            }
            if(fl) cnt1++;
        }
        cnt2 = c/2;
        cout << cnt1 << ' ' << cnt2-1 << endl;
    }
    return 0;
}


