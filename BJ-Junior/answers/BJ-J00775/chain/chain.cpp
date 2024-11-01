#include <bits/stdc++.h>
using namespace std;
int t,a[1005][1005],l[1005],b[1005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int n,k,q;
        scanf("%d%d%d",&n,&k,&q);
        memset(b,0,sizeof(b));
        for(int i = 1;i <= n;i++){
            scanf("%d",&l[i]);
            for(int j = 1;j <= l[i];j++){
                scanf("%d",&a[i][j]);
                if(a[i][j] == 1 && b[i] == 0) b[i] = j;
            }
        }
        while(q--){
            int r,c;
            scanf("%d%d",&r,&c);
            if(r == 1){
                int flag = 0;
                for(int i = 1;i <= n;i++){
                    if(b[i] >= 1){
                        for(int j = 1;j <= l[i];j++){
                            if(a[i][j] == c && j - b[i] <= k && flag == 0){
                                flag = 1;
                                break;
                            }
                        }
                    }
                }
                if(flag == 0) printf("0\n");
                else printf("1\n");
            }
        }
    }
    return 0;
}
