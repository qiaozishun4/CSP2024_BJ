#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll t,n;
ll st[10]={-1,-1,1,7,4,2,6};
ll f[10]={8,10,18,200,20,28,68};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        if(n<7) printf("%lld\n",st[n]);
        else if(n==10) printf("22\n");
        else{
            ll k1=(n/7)-1,k2=n%7;
            if(k2==3) k1--;
            printf("%lld",f[k2]);
            for(int i=1;i<=k1;i++) printf("8");
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
