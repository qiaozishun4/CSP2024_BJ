#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int l[100005], r[100005], s[100005];
struct car{
    int cl, cr;
};
car c[100005];
bool cmp(car x, car y){
    if (x.cr != y.cr) return x.cr < y.cr;
    return x.cl < y.cl;
}
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T; cin >> T;
    while (T--){
        int n, m, L, k; cin >> n >> m >>L >> k;
        for (int i = 1; i <= n; i++){
            int d, v, a; cin >> d >> v >> a;
            //cout << d << " " << v << " " << a << endl;
            if (a > 0 && v > k) l[i] = d, r[i] = L;
            else if (a <= 0 && v <= k) l[i] = -1, r[i] = -1;
            else if (a == 0){
                l[i] = d, r[i] = L;
            }
            else {
                //double t = (k - v) /a;
                double s = 1.0*(k*k-v*v)/(2*a);
                if (a > 0){
                    l[i] = (int)ceil(s)+d, r[i] = L;
                    if ((int)s == (int)ceil(s)) l[i]++;
                }
                else{
                    l[i] = d, r[i] = (int)(s)+d;
                    if ((int)s == (int)ceil(s)) r[i]--;
                }
            }
            //cout << "______" << endl;
        }

        for (int i = 1; i <= m; i++){
            cin >> s[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++){
            bool f = false;
            //cout << l[i] << "'" << r[i] << endl;
            for (int j = 1; j <= m; j++){
                if (l[i] <= s[j] && r[i] >= s[j]) {
                    if (!f) c[i].cl = j;
                    c[i].cr = j;
                    f = true;
                    //cout << "_" << endl;
                }
                //cout << i << " " << j << endl;
            }
            if (f) ans++;
        }
        cout << ans << " ";
        sort(c+1,c+n+1,cmp);
        int cnt = 0;
        int x = c[1].cr;
        int i = 1;
        bool f = false;
        while (i <= n){
            cnt++;
            x = c[i].cr;
            if (x == 0) f = true;
            //cout << i << "-" << x << endl;
            while (x >= c[i+1].cl){
                i++;
                if (i >= n) break;
                //cout << i << endl;
            }
            i++;
        }
        //cout << "--" << endl;
        if (f) cnt--;
        cout << m-cnt << endl;
        for (int i = 1; i <= n; i++) c[i].cl = 0, c[i].cr = 0;
    }
return 0;}
