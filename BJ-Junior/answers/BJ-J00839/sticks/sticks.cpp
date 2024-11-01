#include<bits/stdc++.h>
#define rd(x) scanf("%lld",&x)
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll T,n,a[10]={1,5,2,2,3,2,1,4,0,1},ans[N],la;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    rd(T);
    while(T--){
        rd(n);
        ll len=n/7+(n%7!=0);la=0;
        n=len*7-n;
        for(ll i=1;i<=len;i++){
            for(ll j=(i==1);j<=9;j++){
                if((len-i)*5>=n-a[j]&&n>=a[j]){
                    n-=a[j];
                    ans[++la]=j;
                    break;
                }
            }
        }
        if(la!=len){
            printf("-1");
        }else{
            for(ll i=1;i<=la;i++){
                printf("%lld",ans[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
