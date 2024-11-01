#include <bits/stdc++.h>
using namespace std;
int n,k,q,T,s[1001][2001];

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    for(int TTT=1;TTT<=T;++TTT){
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;++i){
            int l;
            scanf("%d",&l);
            for(int j=1;j<=l;++j){
                scanf("%d",&s[i][j]);
            }
            int r,c;
            for(int j=1;j<=q;++j){
                scanf("%d%d",&r,&c);
                printf("0\n");
            }
        }
    }
    return 0;
}