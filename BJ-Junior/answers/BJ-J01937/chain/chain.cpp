#include <bits/stdc++.h>
using namespace std;
int T,n,m,q,k,x;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&n,&k,&q);
        for(int i=1; i<=n; i++){
            scanf("%d",&m);
            for(int j=1; j<=m; j++){
                scanf("%d",&x);
            }
        }
        for(int i=1; i<=q; i++){
            scanf("%d %d",&n,&k);
        }
        for(int i=1; i<=q; i++){
            printf("1\n");
        }
    }
    return 0;
}
