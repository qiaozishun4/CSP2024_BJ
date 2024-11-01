#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+1e3;
const int num[10]={6,2,5,5,4,5,6,3,7,6};
int T,n,f[N];
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n+40;i++) f[i]=LLONG_MAX/10-10;
        for(int j=0;j<=n+10;j++){
            for(int i=0;i<=9;i++){
                if(!f[j] && !i) continue;
                f[j+num[i]]=min(f[j+num[i]],f[j]*10+i);
            }
        }
        if(f[n]==LLONG_MAX/10-10) puts("-1");
        else printf("%lld\n",f[n]);
    }
    return 0;
}
