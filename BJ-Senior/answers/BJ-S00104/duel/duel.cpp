#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int ans, n, a[N];
signed main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    int ch = 0;
    for(int i = 1, j;i <= n;i = j){
        j = i + 1;
        while(a[i] == a[j])j++;
        int len = j - i;
        int nkill = min(len, ch);
        ans += nkill;
        ch -= nkill;
        ch += len;
    }
    cout << n - ans << '\n';
    return 0;
}
