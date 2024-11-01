#include<bits/stdc++.h>
#define ll long long
#define lson pos<<1
#define rson pos<<1|1
using namespace std;
const int maxn=1e5+10;
const ll mod=998244353;
const ll inf=1e9+10;
ll n,m;
ll a[maxn];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%lld",&n);

    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

    sort(a+1,a+1+n);

    int cnt=0;
    int l=1;
    for(int i=2;i<=n;i++){
          //  cout<<a[l]<<" "<<a[i]<<endl;
        if(a[l]<a[i]&&l<i) l++,cnt++;
    }

    printf("%lld",n-cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}