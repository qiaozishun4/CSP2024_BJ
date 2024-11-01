#include<bits/stdc++.h>
using namespace std;
#define int long long
int d[100010];
int v[100010];
int a[100010];
int p[100010];
bool f[100010];
signed main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin >> t;
    for (int o=1;o<=t;o++) {
        int n,m,L,V;
        cin >> n >> m >> L >> V;
        for (int i=1;i<=n;i++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i=1;i<=m;i++) {
            cin >> p[i];
        }
        int c = 0;
        int x = 0;
        int xx = 0;
        int yy = L;
        for (int i=1;i<=n;i++) {
            if (d[i] > p[m]) {
                continue;
            }
            int z = p[m]-d[i];
            int l = 1,r = m;
            int jl = 0;
            while (l<r) {
                int mid = (l+r)/2;
                if (p[mid] >= d[i]) {
                    if (p[mid]-d[i] < z) {
                        z = p[mid]-d[i];
                        jl = mid;
                    }
                    z = min(z,p[mid]-d[i]);
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (a[i] == 0) {
                if (v[i] > V) {
                    c++;
                    x = max(x,d[i]);
                }
            } else if (a[i] < 0) {
                if (pow(v[i],2)+2.0*a[i]*z < 0) {
                    continue;
                }
                double su = sqrt(pow(v[i],2)+2.0*a[i]*(p[jl]-d[i]));
                if (su > V) {
                    c++;
                }
            } else if (a[i] > 0) {
                double su = sqrt(pow(v[i],2)+2.0*a[i]*(p[m]-d[i]));
                if (su > V) {
                    c++;
                    x = max(x,d[i]);
                }
            }
        }
        int ans = 0;
        bool flag = false;
        for (int i=1;i<=m;i++) {
            if (f[i]) {
                if (p[i] >= x) {
                    flag = true;
                }
                ans++;
                f[i] = false;
            }
        }
        if (!flag) {
            ans++;
        }
        if (c == 0) {
            ans++;
        }
        cout << c << " " << m-ans << endl;
    }
    return 0;
}
