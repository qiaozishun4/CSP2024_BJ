#include<bits/stdc++.h>
using namespace std;
int cnt[55];
int main() {
    freopen ("poker.in", "r", stdin);
    freopen ("poker.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        if (a == 'D') {
            if (b == 'A') {
                cnt[1]++;
            } else if (b == 'T') {
                cnt[10]++;
            } else if (b == 'J' ){
                cnt[11]++;
            } else if (b == 'Q') {
                cnt[12]++;
            } else if (b == 'K') {
                cnt[13]++;
            } else {
                cnt[b - '0']++;
            }
        } else if (a == 'C') {
            if (b == 'A') {
                cnt[14]++;
            } else if (b == 'T') {
                cnt[23]++;
            } else if (b == 'J' ){
                cnt[24]++;
            } else if (b == 'Q') {
                cnt[25]++;
            } else if (b == 'K') {
                cnt[26]++;
            } else {
                cnt[b - '0' + 13]++;
            }
        } else if (a == 'H') {
            if (b == 'A') {
                cnt[27]++;
            } else if (b == 'T') {
                cnt[36]++;
            } else if (b == 'J' ){
                cnt[37]++;
            } else if (b == 'Q') {
                cnt[38]++;
            } else if (b == 'K') {
                cnt[39]++;
            } else {
                cnt[b - '0' + 26]++;
            }
        } else {
            if (b == 'A') {
                cnt[40]++;
            } else if (b == 'T') {
                cnt[49]++;
            } else if (b == 'J' ){
                cnt[50]++;
            } else if (b == 'Q') {
                cnt[51]++;
            } else if (b == 'K') {
                cnt[52]++;
            } else {
                cnt[b - '0' + 39]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 52; i++) {
        if (cnt[i] == 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}