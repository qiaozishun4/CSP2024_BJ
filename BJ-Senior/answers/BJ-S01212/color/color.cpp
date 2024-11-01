#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MAX = 1e6 + 5;

int t;

int n;

int p[N] = {};
int cnt[MAX] = {};

int a;

int maxx;

long long ans;

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    cin >> t;

    while(t--) {
        ans = 0;
        maxx = -1;
        for(int i = 1; i < MAX; i++) cnt[i] = 0;

        cin >> n;

        for(int i = 1; i <= n; i++) {
            cin >> p[i];
            cnt[p[i]]++;
            maxx = max(maxx, p[i]);
        }

        sort(p+1, p+n+1);
        bool pd = 1;
        for(int i = 1; i < n; i++) {
            if(p[i]==p[i+1]){
                pd = 0;
                i = n;
            }
        }
        if(pd) cout << 0 << endl;
        else{
            for(int i = 1; i <= maxx; i++) {
                if(cnt[i]>1) ans += i * (cnt[i]-1);
            }
            cout << ans << endl;
        }


    }

    return 0;
}
