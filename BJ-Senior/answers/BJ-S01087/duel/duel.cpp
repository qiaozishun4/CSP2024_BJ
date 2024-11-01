#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n,x,t[N],sum[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> x;
        t[x]++;
    }
    int ans = t[1];
    for (int i = 2 ; i <= 1e5 ; i++){
        ans = max(0,ans - t[i]);
        ans += t[i];
    }
    cout << ans;
    return 0;
}
