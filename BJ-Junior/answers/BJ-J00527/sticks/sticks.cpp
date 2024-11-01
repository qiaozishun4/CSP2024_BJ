#include <bits/stdc++.h>
using namespace std;
int T,n;
long long f[100001];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    for(int j=1;j<=T;++j){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            f[i]=10000000000000000;
        }
        f[2]=1,f[5]=2,f[4]=4,f[6]=6,f[3]=7,f[7]=8;
        for(int i=9;i<=n;++i){
            f[i]=min(min(min(min(min(min(f[i],f[i-2]*10+1),f[i-5]*10+2),f[i-4]*10+4),f[i-6]*10+0),f[i-3]*10+7),f[i-7]*10+8);
        }
        if(f[n]!=10000000000000000)printf("%lld\n",f[n]);
        else printf("-1\n");
    }
    return 0;
}
