#include<bits/stdc++.h>
using namespace std;
int T;
int n,k,q;
int l[2005],s[2005][1005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&l[i]);
            for(int j=1;j<=l[i];j++){
                scanf("%d",&s[i][j]);
            }
        }
        while(q--){
            int r,c,flag=0;
            scanf("%d%d",&r,&c);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=l[i];j++){
                    if(s[i][j]==1){
                        for(int m=j;m<=j+k-1;m++){
                            if(s[i][m]==c){
                                flag=1;
                            }
                        }
                    }
                }
            }
            printf("%d\n",flag);
        }
    }
    return 0;
}
