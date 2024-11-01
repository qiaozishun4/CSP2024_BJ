#include<bits/stdc++.h>
using namespace std;
int n, a[100005], b[100005];
int minn = 100000000, maxn = 0;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        min(a[i], minn);
        max(maxn, a[i]);
    }
    if(maxn == 2) {
        int cnt = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == 1) sum++;
            if(a[i] == 2) cnt++;
        }
        n = max(sum, cnt);
        cout << n << endl;
        return 0;
    }
    sort(a+1, a+n+1);
    int cnt = n, ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == minn) continue;
        else {
            ans++;
            minn = b[ans];
            cnt--;
        }
    }
    cout << cnt+1 << endl;
    return 0;
}