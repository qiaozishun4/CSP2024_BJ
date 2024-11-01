#include <bits/stdc++.h>

using namespace std;
const int MAXN = 200002;

int n;
int ans;
int a[MAXN];
int cnt[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(int i = 1;i <= 100000;i++)
        ans = max(ans,cnt[i]);
    cout << ans << '\n';

    return 0;
}