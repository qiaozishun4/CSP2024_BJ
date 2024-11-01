#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int M = 1e6 + 5;
int t;
int n,  m;
ll L, V;
ll d[N], v[N], a[N], p[N];
int bucket[N];
int main() {
    freopen("detect.in","r", stdin);
    freopen("detect.out", "w", stdout);
    cin>>t;
    while(t--){
        memset(bucket, 0, sizeof(bucket));

        cin >>n >>m >>L >>V;
        for(int i = 1;i  <= n;i++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i = 1; i <= m ; i++) {
            cin >> p[i];
        }
        sort(p + 1, p + m + 1);
        ll ans = 0;
        ll cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] > 0 ) {
                if(v[i] > V) {
                    int pp = lower_bound(p + 1, p + m +1, d[i]) - p;
                    ans++;
                    bool flag = false;
                    for(int j = pp; j <= m; j++) {
                        if(bucket[j]) {
                            continue;
                        }
                    }
                    bucket[pp]++;
                    cnt++;

                } else {
                    double t = (V - v[i]) * 1.0 / a[i];
                    double s = t * v[i]  + 0.5 * a[i] * t * t;
                    if(s + d[i] < L) {
                        ll ss = 0;
                        if(s - ll(s) > 0.0001) {
                            ss = ll(s) + 1;
                        } else {
                            ss = ll(s);
                        }
                        int pp = upper_bound(p +1, p + m + 1, s + d[i]) - p;
                        ans++;
                        for(int j = pp; j <= m; j++) {
                            if(bucket[j]) {
                                continue;
                            }
                        }
                        bucket[pp]++;
                        cnt++;
                    }
                }

            } else if(a[i] == 0 ) {
                if(v[i] > V) {
                    int pp = lower_bound(p +1, p + m +1, d[i]) - p;
                    ans++;
                    for(int j = pp; j <= m; j++) {
                            if(bucket[j]) {
                                continue;
                            }
                    }
                    bucket[pp]++;
                    cnt++;
                }
            } else if(a[i] < 0) {
                if(v[i] > V) {
                    double t = (V - v[i]) * 1.0 / a[i];
                    double s = t * v[i] + 0.5 * a[i] * t * t;
                    ll ss = ll(s);
                    int qq = lower_bound(p + 1, p + m + 1, d[i]) - p;
                    int pp = upper_bound(p + 1, p + m + 1, d[i] + s) - p - 1;
                    if(qq <= pp) {
                        ans++;
                        for(int j = qq; j <= pp; j++) {
                            if(bucket[j]) {
                                continue;
                            }
                        }
                        bucket[pp]++;
                        cnt++;
                    }
                }
            }
        }

        cout << ans << " " << cnt << endl;
    }

    return 0;
}
