#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
ll a[MAXN];
ll b[MAXN];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    ll n,ans=0,ts,cnt=0;
    cin>>n;
    ts=n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        b[a[i]]++;
    }
    sort(a+1,a+1+n);
    n=unique(a+1,a+1+n)-(a+1);
    for(int i=2; i<=n; i++){
//        cout<<a[i]<<" "<<cnt<<" "<<b[a[i]]<<" "<<b[a[i-1]]+cnt<<" "<<min(b[a[i]],b[a[i-1]]+cnt)<<endl;
        ans=ans+min(b[a[i]],b[a[i-1]]+cnt);
        cnt=b[a[i-1]]+cnt-min(b[a[i]],b[a[i-1]]+cnt);
    }
    cout<<ts-ans<<endl;
    return 0;
}
