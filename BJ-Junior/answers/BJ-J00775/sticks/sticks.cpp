#include <bits/stdc++.h>
using namespace std;
int t,a[15] = {6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int n,ans = 1e9;
        scanf("%d",&n);
        if(n == 6){
            printf("6\n");
            continue;
        }
        for(int i = 0;i <= 9;i++){
            for(int j = 0;j <= 9;j++){
                for(int k = 0;k <= 9;k++){
                    if(i != 0){
                        if(a[i] + a[j] + a[k] == n){
                            ans = min(ans,i * 100 + j * 10 + k);
                        }
                    }else if(j != 0){
                        if(a[j] + a[k] == n){
                            ans = min(ans,j * 10 + k);
                        }
                    }else{
                        if(a[k] == n){
                            ans = min(ans,k);
                        }
                    }
                }
            }
        }
        if(ans != 1e9) printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}
