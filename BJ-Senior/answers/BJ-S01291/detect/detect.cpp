#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t,n[25],m[25],l[25],vx[25],d[100005],v[100005],a[100005],p[100005],pmax;
ll ans1[25],cntt;
int main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for (int i=0;i<t;i++) {
        cin>>n[i]>>m[i]>>l[i]>>vx[i];
        for (int j=0;j<n[i];j++) {
            scanf("%lld%lld%lld",&d[j],&v[j],&a[j]);
        }
        for (int j=0;j<m[i];j++) {
            scanf("%lld",&p[j]);
            if (j==0) {
                pmax=p[j];
            } else {
                if (pmax<p[j]) {
                    pmax=p[j];
                }
            }
        }
        for (int j=0;j<n[i];j++) {
            if (v[j]>vx[i] && d[j]<=pmax) {
                ans1[cntt]++;
            }
        }
        cntt++;
    }
    for (int i=0;i<cntt;i++) {
        cout<<ans1[i]<<" "<<m[i]-1;
    }

    return 0;
}
