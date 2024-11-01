#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll N=1e5;
ll n,a[N+5],len,cnt,b[N+5],buk[N+5],ans,maxx,maxnum;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&a[i]),maxx=max(maxx,a[i]);
    for(ll i=1;i<=n;i++)
        if(a[i]==maxx)
            maxnum++;
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
            b[len]=cnt,len++,cnt=1;
        else cnt++;
    }
    b[len]=cnt;
    for(ll i=2;i<=len;i++)
        buk[i]=b[i]-b[i-1];
    for(ll i=2;i<=len;i++)
        if(buk[i]<0||(buk[i]>0&&ans<0))
            ans=min((ll)0,ans+buk[i]);
    printf("%lld",-ans+maxnum);
    return 0;
}
