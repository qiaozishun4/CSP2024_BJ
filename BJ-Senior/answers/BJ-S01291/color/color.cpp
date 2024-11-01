#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t,n[15],a[200005],s[200005],ans[15],cnt,maxx;
void check(ll n){
    ll ans=0;
    for (int i=1;i<n;i++) {
        for (int j=i-1;j>=0;j--) {
            if (s[i]==s[j] && a[i]==a[j]) {
                ans+=a[i];
            }
        }
    }
    if (maxx<ans) {
        maxx=ans;
    }
}
void prmtt(ll len){
    ll endd=0,i;
    maxx=0;
    memset(s,0,sizeof(s));
    while (endd!=len) {
        endd=0;i=0;
        s[0]++;
        while (s[i]>=2) {
            s[i]=0;
            s[i+1]++;
            i++;
            endd++;
        }
        check(len);
    }
}
int main() {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for (int i=0;i<t;i++) {
        cin>>n[i];
        for (int j=0;j<n[i];j++) {
            scanf("%lld",&a[j]);
        }
        prmtt(n[i]);
        ans[cnt]=maxx;
        cnt++;
    }
    for (int i=0;i<cnt;i++) {
        cout<<ans[i]<<endl;
    }

    return 0;
}
