#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, a[100010], m, b[100010], c[100010], k, d;
ll ans;

int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>b[i];
    }
    for(int i=1;i<=m;i++) {
        cin>>c[i];
    }
    k=ceil(log2(n));
    for(int i=1;i<=k;i++) cin>>d;
    int T;
    cin>>T;
    while(T--) {
        ll x[5];
        cin>>x[1]>>x[2]>>x[3]>>x[4];
        for(int i=1;i<=n;i++) a[i]=b[i]^x[i%4+1];
        ll ans=0;
        for(int i=1;i<=m;i++) {
            ll res=(n+i+1)*(n-i)/2;
            for(int j=1;j<=c[i];j++) {
                if(a[i]>=k) {
                    res=j;
                    break;
                }
            }
            if(i==1) ans=res;
            else ans = ans ^ (i * res);
        }
        cout<<ans<<endl;
    }
    return 0;
}
