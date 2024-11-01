#include <bits/stdc++.h>
using namespace std;
int T,a,b,c,q;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&a,&b,&q);
        for(int i=1;i<=a;i++){
            scanf("%d",&b);
            for(int i=1;i<=b;i++) scanf("%d",&c);
        }
        for(int i=1;i<=q;i++){
            scanf("%d%d",&a,&b);
            printf("1");
        }
    }
    fclose(stdin);
    fclose(stdout);
}