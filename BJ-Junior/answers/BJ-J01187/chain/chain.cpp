#include<bits/stdc++.h>
using namespace std;
long long T,a[1003][1003],l[1003];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        long long n,k,q;
        scanf("%lld%lld%lld",&n,&k,&q);
        for(int i=1;i<=n;i++){
            scanf("%lld",&l[i]);
            for(int j=1;j<=l[i];j++){
                scanf("%lld",&a[i][j]);
            }
        }
        while(q--){
            long long x,y;
            scanf("%lld%lld",&x,&y);
            if(x==1){
                long long flag=0;
                for(int i=1;i<=n;i++){
                    
                    for(int j=1;j<=l[i];j++){
                        if(a[i][j]!=1)continue;
                        for(int z=j+1;z<=l[i];z++){
                            if(z-j>=k)break;
                            if(a[i][z]==y){
                                flag=1;
                                break;
                            }
                        }
                        if(flag==1)break;
                    }
                    if(flag==1)break;
                }
                if(flag==1){
                    printf("1\n");
                }
                else printf("0\n");
            }
            else{
                printf("0\n");
            }
        }
    }
    return 0;
}