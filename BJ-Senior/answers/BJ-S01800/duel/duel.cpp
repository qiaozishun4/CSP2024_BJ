# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 1e5 + 5;
int n, ans;
int a[N], cnt[N];
int nowmax;
signed main()
{
    ios::sync_with_stdio(0);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a + 1, a + n + 1, greater <int> ());
    ans = n;
    nowmax = 1e5;
    for(int i = 1; i <= n; i++)
    {
        while(nowmax > 0 && cnt[nowmax] == 0) nowmax--;
        //if(nowmax == 0) break;
        if(nowmax == a[i]) continue;
        //cout << nowmax << endl;
        cnt[nowmax]--;
        //cnt[a[i]]--;
        ans -= 1;
    }
    cout << ans << endl;
    return 0;
}
