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
int n,m,a[N],cnt[N];
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++,m=max(m,a[i]);
    int cur=0,ans=0;
    for(int i=1;i<=m;i++) to_max(ans,cnt[i]);
    cout<<ans<<endl;
}
