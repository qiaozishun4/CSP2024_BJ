#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void IOS(){ios::sync_with_stdio(false);cin.tie(0);}
const int INF=100'000'000'000'000'000;
const int mod=998244353;
void add(int& x,int y){x=(x+y)%mod;}
void mul(int& x,int y){x=x*y%mod;}
void to_min(int& x,int y){if(x>y) x=y;}
void to_max(int& x,int y){if(x<y) x=y;}
const int N=1000010;
int n,a[N],pre[N],f[N],lst[N],mx[N];
int calc(int l,int r){
    if(l>=r) return 0;
    return pre[r]-pre[l];
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],pre[i]=a[i]*(a[i]==a[i-1]),lst[a[i]]=0;
    for(int i=1;i<=n;i++) pre[i]+=pre[i-1];
    for(int i=1;i<=n;i++){
        if(!lst[a[i]]){lst[a[i]]=i;f[i]=0;mx[i]=mx[i-1];continue;}
        int j=lst[a[i]];
        if(j+1==i) f[i]=mx[j]+a[i];
        else f[i]=mx[j+1]+a[i]+calc(j+1,i-1);
        lst[a[i]]=i;mx[i]=max(f[i],mx[i-1]);
    }
    int ans=0;
    for(int i=1;i<=n;i++) to_max(ans,f[i]);
    cout<<ans<<endl;
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    IOS();
    int T;cin>>T;
    while(T--) solve();
}
