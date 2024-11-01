#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], cnt1[N], cnt2[N];
int main(){
    freopen("duel.in","r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        cnt1[a[i]] ++, cnt2[a[i]] ++;
        mx = max(mx, a[i]);
    }
    for (int i = 1, j = 2; i <= mx;)
    {
        while (i <= mx && cnt1[i] == 0) i ++;
        if (i > mx) break;
        j = max(j, i + 1);
        while (j <= mx && cnt2[j] == 0) j ++;
        if (j > mx) break;
        if (cnt1[i] >= cnt2[j]) cnt1[i] -= cnt2[j], cnt2[j] = 0;
        else cnt2[j] -= cnt1[i], cnt1[i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= mx; i ++)
        ans += cnt1[i];
    cout << ans;

    return 0;
}