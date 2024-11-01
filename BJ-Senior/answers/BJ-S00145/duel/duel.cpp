#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, cnt[100010];
ll ans, _max;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        ll x;
        cin>>x;
        cnt[x]++;
        _max=max(_max, x);
    }
    for(int i=1;i<=_max;i++) {
        ans=max(ans-cnt[i], 0ll);
        ans+=cnt[i];
    }
    cout<<ans;
    return 0;
}

// Last Updated UTC+8 2024/10/26 SAT 14:53
// 100pts O(n)