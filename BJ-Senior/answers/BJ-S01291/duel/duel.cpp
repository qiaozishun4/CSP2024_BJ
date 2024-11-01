#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,r[100005],ans,ri,cnt;
int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for (int i=0;i<n;i++) {
        scanf("%lld",&r[i]);
    }
    sort(r,r+n);
    ri=r[0];
    for (int i=1;i<n;i++) {
        if (r[i]>ri){
            cnt++;
            ri=r[cnt];
            ans--;
        }
    }
    cout<<ans;

    return 0;
}
