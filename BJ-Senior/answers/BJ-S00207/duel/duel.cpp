#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
ll n;
ll r[100010];
ll ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    memset(r,0x3f,sizeof(r));
    cin >> n;
    for(ll i = 1;i <= n;i ++){
        cin >> r[i];
    }
    sort(r + 1,r + 1 + n);
    for(ll i = 1;i <= n;i ++){
        ll loc = lower_bound(r + 1,r + 1 + n,r[i]) - r;
        loc --;
        if(r[i] > r[loc]){
            r[loc] = 9e18;
            ans ++;
        }
    }
    cout << n - ans;
    return 0;
}