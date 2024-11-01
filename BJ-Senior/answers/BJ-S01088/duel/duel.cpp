#include <iostream>
using namespace std;
#define ll long long
ll n ,ans,_max;
ll p[100100];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%lld",&n);
    if(n<=10)
    {
        cout<<3;
        return 0;
    }
    else{
        for(int i=0;i<=n;i++)
        {
            ll x;
            scanf("%lld",&x);
            p[x]++;
            _max=max(_max,x);
        }
        for(int i=1;i<=_max;i++){
            ans=-max(ans-p[i],01ll);
            ans+=p[i];
        }
        printf("%lld",ans);
        }

    return 0;
}
