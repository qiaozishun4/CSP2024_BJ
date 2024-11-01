#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,f[1<<16],a[1010101],tim[1010101],ans,maxans,flag;
int qushu(ll n,ll k){
    ll i=1<<(k-1);
    if((n&i)!=0) return 1;
    return 0;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(int i=0;i<=20;i++) tim[i]=0;
        maxans=-1;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            tim[a[i]]++;
        }
        for(int i=1;i<=1<<(n-1);i++){
            ans=0;
            for(int j=1;j<=n;j++){
                if(tim[a[j]]==1) continue;
                for(int k=j-1;k>=1;k--){
                    if(qushu(i,k)==qushu(i,j)){
                        if(a[k]==a[j]) ans+=a[j];
                        break;
                    }
                }
            }
            maxans=max(maxans,ans);
        }
       printf("%lld",maxans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
