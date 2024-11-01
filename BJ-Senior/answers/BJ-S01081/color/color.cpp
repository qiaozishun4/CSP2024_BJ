#include <iostream>
#include <cstdio>
using namespace std;

int n, a[16], b[16], d[16], e[16];
bool c[16]; long long ans = 0;

void dfs(int t) {
    if(t == 0) {
        int i;
        long long sum = 0;
        for(i = 1; i <= n; i++) {
                b[i] = 0;
        }
        for(i = 1; i <= n; i++) {
                d[i] = e[i] = -1;
            if(i == 1) {
                e[i] = d[i] = -1;
                continue;
            }
            if(i == 2) {
                if(c[2] != c[1]) {
                    d[i] = -1;
                    e[i] = 1;
                }
                else {
                    d[i] = 1;
                    e[i] = -1;
                    if(a[i] == a[i - 1]) {
                        b[i] = a[i];
                    }
                }
                continue;
            }
            if(c[i] == c[i - 1]) {
                d[i] = i - 1;
                e[i] = e[i - 1];
                if(a[i] == a[i - 1]) {
                    b[i] = a[i];
                }
            }
            //else {
            //    if(b[i - 1] = )
            //    b[i] = a[i];
            //    
            //}
        }
        for(i = 1; i <= n; i++) {
            sum += d[i];
        }
        ans = max(ans, sum);
        return;
    }
    
    c[n - i + 1] = true;
    dfs(t - 1);
    c[n - i + 1] = false;
    dfs(t - 1);
    return;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T; cin >> T;
    while((T--) > 0) {
            ans = 0;
        int n; cin >>n;
        for(i = 1; i <= n; i++) {
            cin >>a[i];
        }
        dfs(n);
        cout <<ans << endl;
    }
    return 0;
}