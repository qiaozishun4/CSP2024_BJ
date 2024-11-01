#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll a[N],n,j=2;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
    scanf("%lld",&a[i]);}
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        while(j<=n&&a[j]<=a[i]) j++;
        if(a[j]<=a[i]){
        printf("%lld",n-i+1); break;}
        else j++;
    }
    return 0;
}
